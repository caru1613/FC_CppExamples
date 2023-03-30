#include <vector>

class Person;
class Villiage
{
    private:
        std::vector<Person> persons;
    public:
        void add(Person* person);
};
