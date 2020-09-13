#include "a.h"
#include "b.h"
#include <iostream>
void f(B *) {
    std::cout << "f1" << std::endl;
}

void f(void *) {
    std::cout << "f2" << std::endl;
}
