#include <iostream>
#include "Character.h"

using namespace std;


class Base
{
public:
    virtual void virtualFunc()
    {
        cout << "virtual Base" << endl;
    }

    void nonVirtualFunc()
    {
        cout << "nonVirtual Base" << endl;
    }
};


class Derived : public Base
{
public:
    virtual void virtualFunc() override // override 를 붙여서 실수를 방지하자
    {
        cout << "virtual Derived" << endl;
    }

    //virtual void virtualFunc(int) override 함수의 시그니쳐가 다르다면 override 할 수 없다
    //{
    //    cout << "virtual Derived" << endl;
    //}

    void nonVirtualFunc() // override가 아닌 hide, 가리게 되면 실행 도중 타입이 아닌 컴파일 타임의 타입으로 함수를 호출한다
    {
        cout << "nonVirtual Derived" << endl;
    }
};


class Derived1 : public Derived
{
public:
    virtual void virtualFunc() override
    {
        cout << "virtual Derived1" << endl;
    }
};


void foo(Base& base)
{
    base.virtualFunc();
}


int main()
{
    Base b;
    Derived d;

    cout << "Base b & Derived d" << endl;
    /*
     * Base b & Derived d
       nonVirtual Base
       nonVirtual Derived
       virtual Base
       virtual Derived
    */
    b.nonVirtualFunc(); // Base
    d.nonVirtualFunc(); // Derived
    b.virtualFunc(); // Base
    d.virtualFunc(); // Derived

    cout << "Base& b0 = d" << endl;
    /* 
     * Base& b0 = d
       nonVirtual Base
       virtual Derived
    */
    Base& b0 = d;
    b0.nonVirtualFunc(); // Base
    b0.virtualFunc(); // Derived

    cout << "Base* b1 = &d" << endl;
    /*
     * Base* b1 = &d
       nonVirtual Base
       virtual Derived
     */
    Base* b1 = &d;
    b1->nonVirtualFunc(); // Base
    b1->virtualFunc(); // Derived

    cout << "foo(b), foo(d)" << endl;
    /*
      foo(b), foo(d)
      virtual Base
      virtual Derived
    */
    foo(b); // Base
    foo(d); // Derived

    cout << "Player and Monster" << endl;
    /*
     * Player and Monster
       으악
       꿰엑
    */
    Player player(100, 10);
    Monster monster(200, 20);

    monster.attack(player);
    player.attack(monster);

    cout << "Character" << endl;
    /* 
     * Character
       ~Player
       ~Character
     */

    Character* ch = new Player(100, 10);
    delete ch;

    /* Destory */
    /*
       Destroy
       ~Monster
       ~Character
       ~Player
       ~Character
     */
    cout << "Destroy" << endl;
}
