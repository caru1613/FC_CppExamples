#include <iostream>

using namespace std;

void func();

void func()
{
    cout << "func" << endl;
}

#if 0
void func()
{
    cout << "func" << endl; 
}
#endif
