#include <iostream>

using namespace std;

class Player3
{
    private:
        int _health;
        int _power;

    public: 
        Player3() : Player3(100, 50)
        {
        }

        Player3(int health, int power)
        {
            _health = health;
            _power = power;

            cout << "Player " << _health <<", " << _power << endl;
        }

        void print()
        {
            cout << _health << endl;
            cout << _power << endl;
        }
};

void player3_main()
{
    cout << "Player3" << endl;
    Player3 player;

    player.print();
}
