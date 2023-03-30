#include "swap.h"

template<typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

#if 1
template<>
#endif
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
