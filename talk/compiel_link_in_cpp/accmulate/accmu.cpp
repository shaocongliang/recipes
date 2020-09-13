#include <stdio.h>
int sum() {
  int ret = 0;
  int i;
  for (i = 1; i <= 100; i++) ret += i;
  return ret;
}
int main() {
  printf("%d\n", sum());
  return 0;
}