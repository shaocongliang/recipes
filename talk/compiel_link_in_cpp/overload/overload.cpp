#include <iostream>
template <typename T>
void foo(const T &lhs, const T &rhs) {
    std::cout << "v1" << std::endl;
}
void foo(const char *lhs, const char *rhs) {
    std::cout << "v2" << std::endl;
}
int main(void){
    char p1[] = "hao jin";
    char p2[] = "hao jin";
    foo(p1, p2);
}