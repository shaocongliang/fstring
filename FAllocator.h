/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-04
 */

#ifndef FSTRING_FALLOCATOR_H
#define FSTRING_FALLOCATOR_H
#include <cstdio>
#include <cstdlib>
namespace sc{
template <typename Tp>
class FAllocator{
 public:
  Tp* allocate(const size_t nb){
    return static_cast<Tp*>(malloc(nb* sizeof(Tp)));
  }

  void deallocate(Tp *ptr){
    free(static_cast<void*>(ptr));
  }
};
}
#endif //FSTRING_FALLOCATOR_H
