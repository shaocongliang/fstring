/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-03
 */

#ifndef FSTRING_H
#define FSTRING_H

#include <FAllocator.h>

#include <atomic>
#include <assert.h>

namespace sc {
typedef std::atomic_int FAtomicInt;
typedef FAllocator<char> FAlloc;

class FString {
 public:
  // ctor
  FString():rcPtr_(nullptr), len_(0){}

  FString(const char *str):rcPtr_(nullptr) {
    cpyCStr(str);
    rcPtr_ = new FAtomicInt();
    incrementRC();
  }
  FString(const FString &rhs);

  FString& operator =(const FString &rhs);

  // capacity
  size_t length() const { return len_; }
  size_t size() const {return length(); }
  bool empty() const { return len_ == 0; }

  // element access
  const char* cstr() const {
    return str_;
  }

  // debug function
  int rc() const {
    if(rcPtr_) return rcPtr_->load();
    return 0;
  }

  ~FString(){
    if(rcPtr_ && *rcPtr_!= 0)
      destroy();
  }
 private:
  inline void incrementRC() {
    assert(*rcPtr_ >= 0);
    void((*rcPtr_)++);
  }

  inline void decrementRC(){
    assert(*rcPtr_ > 0);
    void((*rcPtr_)--);
  }

  void destroy(){
    if(rcPtr_){
      decrementRC();
      if(*rcPtr_==0){
        delete rcPtr_;
        alloc_.deallocate(str_);
      }
    }
  }

  void cpy(const FString &src, FString &dst);
  void cpyCStr(const char *str);

  mutable FAtomicInt *rcPtr_;
  FAlloc alloc_;

  size_t len_;
  char *str_;
};

bool operator ==(const FString &lhs, const FString &rhs);
}
#endif //FSTRING_H
