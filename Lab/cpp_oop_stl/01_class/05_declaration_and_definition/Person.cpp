#include "Person.h"

Person::Person(float weight, float height, const std::string& name)
    : _weight(_weight), _height(height), _name(name)
{

}

void Person::print()
{
    using namespace std;
    cout << _name << endl;
}

void foo()
{
    Person p(60.f, 160.f, "David");
    p.print();
}
