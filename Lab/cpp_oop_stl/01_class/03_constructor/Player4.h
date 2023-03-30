#include <iostream>
#include <string>

using namespace std;

class Player4
{
    private:
        int _health;
        int _power;
        const string _name;

    public: 
        Player4() : Player4(100, 50, "noname")
        {
        }

        Player4(int health, int power, string name)
            : _health(health), _power(power), _name(name)
        {
#if 0
            _health = health;
            _power = power;
            _name = name; //It causes build error as _name is const and initialized.
#endif
            cout << "Player " << _health <<", " << _power << endl;
        }

        void print()
        {
            cout << _name << endl;
            cout << _health << endl;
            cout << _power << endl;
        }
};

void player4_main()
{
    cout << "Player4" << endl;
    Player4 player;

    player.print();
}
