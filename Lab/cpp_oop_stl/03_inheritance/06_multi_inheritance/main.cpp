#include <iostream>
#include "case1.h"
#include "case2.h"
#include "case3.h"

using namespace std;


/*
 *
    case 1
    BaseA
    BaseB

    case 2
    Base(10)
    BaseA
    Base(20)
    BaseB
    Derived
    10
    20

    case 3
    Base(30)
    BaseA
    BaseB
    Derived
    30
 *
 * */
// 다중상속은 정말 필요하지 않으면 사용하지 말자
int main()
{
    cout << "case 1" << endl;
    case1::Derived d1;

    // 어떤 부모의 것을 호출해야할지 모호하다
    //d.foo();
    //d.m;

    d1.BaseA::foo();
    cout << d1.BaseA::m << endl;
    d1.BaseB::foo();
    cout << d1.BaseB::m << endl;
    cout << endl;

    cout << "case 2" << endl;
    case2::Derived d2; // Base 생성자 두 번 호출

    // BaseA 부모의 m인지 BaseB 부모의 m인지 모호하다
    //d1.m = 10;

    cout << d2.BaseA::m << endl;
    cout << d2.BaseB::m << endl;
    cout << endl;

    cout << "case 3" << endl;
    case3::Derived d3;

    // Base가 한 개만 만들어지기 때문에 모호하지 않다
    cout << d3.m << endl;
}
