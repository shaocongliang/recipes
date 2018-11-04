/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-04
 */

#include <FString.h>
#include <string.h>

using namespace sc;

FAtomicInt FString::refCount_;

void FString::cpy(const char *src) {
  str_ = alloc_.allocate(strlen(src)+1);
  len_ = strlen(src);
  strcpy(str_, src);
}

FString::FString(const sc::FString &rhs) {
  this->str_ = rhs.str_;
  this->len_ = rhs.len_;
  incrementRC();
}
namespace sc {
bool operator==(const FString &lhs, const FString &rhs) {
  if (&lhs == &rhs) return true;
  if (lhs.cstr() == rhs.cstr()) return true;
  return strcmp(lhs.cstr(), rhs.cstr()) == 0;
}
}
