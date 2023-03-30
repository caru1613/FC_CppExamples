#include <iostream>
#include <vector>
#include "swap.h"

using std::cout;
using std::endl;


// 템플릿 특수화
template<typename T, typename S>
class Test
{
public:
    Test();
    T num0;
    S num1;
};

template<typename T, typename S>
Test<T, S>::Test()
    : num0(0), num1(0)
{
    cout <<"Test<T, S>()" << endl;
}


// 완전 특수화
template<>
class Test<int, float>
{
    public:
        Test();
        int num0;
        float num1;
};

#if 0
template<>
#endif
Test<int, float>::Test()
    : num0(0), num1(0)
{
    cout <<"Test<int, float>()" << endl;
}

// 부분 특수화
template<typename T>
class Test<T, T>
{
    public:
        T num0;
        T num1;
        Test();
};

template<typename T>
Test<T, T>::Test()
    :num0(0), num1(0)
{
    cout <<"Test<T, T>()" << endl;
}

int main()
{
    /* 
     swap<Foo>()
     swap pointer()
     === value ===
     20
     10
    */
    Foo f0, f1;
    swap(f0, f1);

    int x = 10, y = 20;
    int* px = &x, * py = &y;
    swap(px, py);

    cout << " === value === " << endl;
    cout << x << endl;
    cout << y << endl;

    cout << " === class Test === " << endl;
    Test<int, int> t0;
    Test<int, float> t1;
    Test<float, int> t2;
    Test<float, float> t3;

    // bool을 그대로 사용하면 효율이 떨어지기 때문에 vector에서 특수화를 사용한다
    std::vector<bool> vb;
}
