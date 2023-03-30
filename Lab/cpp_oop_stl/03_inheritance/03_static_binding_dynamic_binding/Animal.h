#include <iostream>

class Animal
{
public:
    virtual void eat() const
    {
        std::cout << "Animal eat" << std::endl;
    }

    void walk() const
    {
        std::cout << "Animal walk" << std::endl;
    }
};


class Cat : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "Cat eat" << std::endl;
    }

    void walk() const
    {
        std::cout << "Cat walk" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "Dog eat" << std::endl;
    }

    void walk() const
    {
        std::cout << "Dog walk" << std::endl;
    }
};
