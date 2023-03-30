#include "Ranges.h"
#include <iostream>

using namespace std;

Ranges::Ranges(unsigned begin, unsigned end)
    : _begin(begin), _end(end)
{
    cout << typeid(*this).name() << " " << __func__ << endl;
}

Ranges::Iterator Ranges::begin() const
{
    cout << typeid(*this).name() << " " << __func__ << endl;
    return Iterator(_begin);
}

Ranges::Iterator Ranges::end() const
{
    cout << typeid(*this).name() << " " << __func__ << endl;
    return Iterator(_end);
}

Ranges::Iterator::Iterator(unsigned num)
    : _num(num)
{
    cout << typeid(*this).name() << " " << __func__ << endl;
}

Ranges::Iterator Ranges::Iterator::operator++()
{
   cout << typeid(*this).name() << " " << __func__ << endl;
    ++_num;
    return *this;
}

bool Ranges::Iterator::operator==(const Iterator& other) const
{
    cout << typeid(*this).name() << " " << __func__ << endl;
    return _num == other._num;
}

bool Ranges::Iterator::operator!=(const Iterator& other) const
{
    cout << typeid(*this).name() << " " << __func__ << endl;
    return _num != other._num;
}

unsigned Ranges::Iterator::operator*() const
{
    cout << typeid(*this).name() << " " << __func__ << endl;
    return _num;
}
