/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-04
 */

#include <FString.h>
#include <string.h>
#include <assert.h>
using namespace sc;

void FString::cpyCStr(const char *src){
  str_ = alloc_.allocate(strlen(src)+1);
  len_ = strlen(src);
  strcpy(str_, src);
}

void FString::cpy(const sc::FString &src, sc::FString &dst) {
  dst.str_ = src.str_;
  dst.len_ = src.len_;
  this->rcPtr_ = src.rcPtr_;
}

FString::FString(const sc::FString &src):rcPtr_(nullptr){
  cpy(src, *this);
  incrementRC();
}

FString& FString::operator=(const sc::FString &src) {
  if(this->rcPtr_) {
    decrementRC();
  }
  cpy(src, *this);
  incrementRC();
  return *this;
}

namespace sc {
bool operator==(const FString &lhs, const FString &rhs) {
  if (&lhs == &rhs) return true;
  if (lhs.cstr() == rhs.cstr()) return true;
  return strcmp(lhs.cstr(), rhs.cstr()) == 0;
}
}
