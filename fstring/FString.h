/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-03
 */

#ifndef FSTRING_H
#define FSTRING_H

#include <FAllocator.h>
#include <atomic>

namespace sc {
typedef std::atomic_int FAtomicInt;
typedef FAllocator<char> FAlloc;

class FString {
 public:
  // ctor
  FString() = default;

  FString(const char *str) {
    cpy(str);
    incrementRC();
  }
  FString(const FString &rhs);

  // capacity
  size_t length() const { return len_; }
  size_t size() const {return length(); }

  // element access
  const char* cstr() const {
    return str_;
  }

 private:
  void incrementRC() {
    refCount_++;
  }
  void cpy(const char *str);

  static FAtomicInt refCount_;
  FAlloc alloc_;

  size_t len_;
  char *str_;
};

bool operator ==(const FString &lhs, const FString &rhs);
}
#endif //FSTRING_H
