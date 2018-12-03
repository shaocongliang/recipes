#include "other.h"  
#include "util.h"

int main()
{
  int* i = alloc_mem(int, 1);
  int* i1 = alloc_mem(int, 20);
  char* c = alloc_mem(char, 1);
  dosomething();
  int* i3 = alloc_mem(int, 1);
}