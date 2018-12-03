#include <iostream>
class B;
class D;

extern void f(B *);
extern void f(void *);
void test(D *x){
    std::cout << "test" << std::endl;
    f(x);
}