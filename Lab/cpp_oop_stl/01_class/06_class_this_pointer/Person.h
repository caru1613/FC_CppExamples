#include <iostream>

using namespace std;


class Person
{
private:
    float weight;
    float height;
    string name;

public:
    Person(float weight, float height, const string& NAME)
        : weight(weight), height(height), name(NAME)
    {
        // we can set where value is from with "this->"
        weight; // parameter weight
        this->weight; // class member variable weight


        // name is only set as class member variable.
        // parameter is NAME.
        name; // class member variable  name 
        this->name; // class member variable name
    }

    void loseWeight(float weight)
    {
        // below 2 line points the same height in the class.
        this->height;
        height;

        this->height -= weight;
        if (this->weight < 0)
            this->weight = 0;
    }

    float getBMI()
    {
        return weight / (height * 100 * height * 100);
    }


    Person& complete(Person& person)
    {
        if (this->getBMI() < person.getBMI())
            return *this; // It returns this class;
        else
            return person;
    }


    void doCeremony()
    {
        cout << name << " win!!" << endl;
    }
};


void personFunc()
{
    Person david(67.3f, 172.3f, "david");
    Person daniel(58.3f, 167.3f, "daniel");

    //It calls doCeremony() in class Person which is returned by complete().
    //complete() returns different object as a result.
    daniel.complete(david).doCeremony();
}
