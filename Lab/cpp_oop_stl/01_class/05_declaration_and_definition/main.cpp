#include <iostream>
#include "function.h"
#include "Villiage.h"
#include "Person.h"


using namespace std;

void foo1();

int main()
{
    func(); // function.h
    foo(); // Person.h Person.cpp
    foo1(); // utils.cpp

    Villiage v; // Villiage.h
    v.add(new Person(10, 10, "David")); // Villiage.h Villiage.cpp

    return 0;
}
