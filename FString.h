/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-03
 */

#ifndef FSTRING_H
#define FSTRING_H

#include <FAllocator.h>

#include <atomic>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
namespace detail {
#define FSTRING_ASSERT(x) if(!(x)) \
                  abort();
}
namespace lshaocong {

typedef std::atomic_int AtomicInt;

template<typename Alloc>
class FString {
 private:
  struct RepBase {
    RepBase():refcount_(0), size_(0), capacity_(0){}
    AtomicInt refcount_;
    size_t size_;
    size_t capacity_;
  };

  struct Rep : public RepBase {
    char *data_;

    void dispose(const Alloc &__alloc){
      if(--this->refcount_ == 0){
        destroy(__alloc);
      }
    }

    void destroy(const Alloc &__alloc){
      __alloc.deallocate(data_);
    }
  };
  Rep rep_;

 public:
  typedef size_t size_type;

  static const size_type npos = static_cast<size_type >(-1);
  FString(const char *str, size_t count, Alloc alloc = FAllocator<char>());
  FString(const char *str, Alloc alloc = FAllocator<char>());
  FString(size_t count, char ch, const Alloc &alloc = FAllocator<char>());
  FString(){}
  ~FString(){
  }

  FString& assign(size_t count, char ch);
  FString& assign(const FString &src);
  FString& assign(const char *src, size_t count);

  size_t size() const {
  }

  size_t capacity() const{
  }
};
}
#endif //FSTRING_H
