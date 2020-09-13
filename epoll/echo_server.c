#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// max work queue for epoll
const int MAXWQ = 20;
int MSG_LEN = 1024;

void usage() { printf("usage: echo_server port maxlen\n"); }

void err_sys(const int ret, const int lineno) {
  printf("line %d\tret %d\terrno %d\n", lineno, ret, errno);
}

void err(const int ret, const int lineno) {
  printf("line %d\tret %d\n", lineno, ret);
}

void set_nonblock_sock(int fd) {
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags == -1) return;
  flags = flags | O_NONBLOCK;
}

// 根据网卡名找对应的IP地址
// @name [in] 网卡名
// @addr [out] IP地址
int findaddr_by_ncname(const char *name, char *addr) {
  struct ifaddrs *ifAddrStruct = NULL;
  struct ifaddrs *ifa = NULL;
  void *tmpAddrPtr = NULL;

  getifaddrs(&ifAddrStruct);

  for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
    if (!ifa->ifa_addr) {
      continue;
    }
    if (strcmp(ifa->ifa_name, name) == 0) {
      if (ifa->ifa_addr->sa_family == AF_INET) {
        tmpAddrPtr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
        inet_ntop(AF_INET, tmpAddrPtr, addr, INET_ADDRSTRLEN);
        return 0;
      } else if (ifa->ifa_addr->sa_family == AF_INET6) {
        tmpAddrPtr = &((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
        inet_ntop(AF_INET6, tmpAddrPtr, addr, INET6_ADDRSTRLEN);
        return 0;
      }
    }
  }

  if (ifAddrStruct != NULL) {
    freeifaddrs(ifAddrStruct);
  }

  return -1;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    usage();
    return 0;
  }

  MSG_LEN = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    err_sys(sockfd, __LINE__);
    return 0;
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));

  char ip[16];
  memset(ip, 0, sizeof(ip));
  int ret = findaddr_by_ncname("eth1", ip);
  if (ret) {
    err(__LINE__, ret);
    return 0;
  }

  ret = inet_pton(AF_INET, ip, &addr.sin_addr);
  if (ret != 1) {
    err(ret, __LINE__);
    return 0;
  }

  ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret) {
    err_sys(ret, __LINE__);
    return 0;
  }

  ret = listen(sockfd, 20);
  if (ret) {
    err_sys(ret, __LINE__);
    return 0;
  }

  int epfd = epoll_create(10);
  if (epfd < 0) {
    err_sys(epfd, __LINE__);
  }

  struct epoll_event ev;
  struct epoll_event events[MAXWQ];
  ev.events = EPOLLIN;
  ev.data.fd = sockfd;
  if (epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev) == -1) {
    err_sys(-1, __LINE__);
    return 0;
  }

  int nfds = 0;
  for (;;) {
    nfds = epoll_wait(epfd, events, MAXWQ, -1);
    if (nfds == -1) {
      printf("epoll_wait failuer\n");
      err_sys(-1, __LINE__);
      return 0;
    }
    for (int i = 0; i < nfds; ++i) {
      if (events[i].data.fd == sockfd) {
        socklen_t addr_len = 0;
        int connfd = accept(sockfd, (struct sockaddr *)&addr, &addr_len);
        if (connfd == -1) {
          printf("conn fail\n");
          err_sys(connfd, __LINE__);
          continue;
        }

        set_nonblock_sock(connfd);
        ev.events = EPOLLIN;
        ev.data.fd = connfd;

        if (epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev) == -1) {
          err_sys(-1, __LINE__);
          continue;
        }
      } else {
        int activefd = events[i].data.fd;
        if (events[i].events && EPOLLIN) {
          char rsp[1024];
          memset(rsp, 0, sizeof(rsp));
          ret = read(activefd, rsp, MSG_LEN);
          if(ret == 0){
             if(epoll_ctl(epfd, EPOLL_CTL_DEL, activefd, events)==-1){
                printf("remove conn abnormal\n");
                err_sys(-1, __LINE__);
             }
             close(activefd);
          }
          else if (ret < 0) {
            err_sys(ret, __LINE__);
            return 0;
          }else{
          write(activefd, rsp, MSG_LEN);
          }
        }
      }
    }
  }
  close(sockfd);
  return 0;
}