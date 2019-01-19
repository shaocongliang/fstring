#ifndef FSTRINGFWD_H
#define FSTRINGFWD_H
namespace lshaocong {
template<typename T>
class FAllcoator;

template<typename Alloc>
class FString;

typedef FAllcoator<char> FAlloc;
typedef FString<FAlloc> fstring;
}
#endif