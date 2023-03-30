#include <iostream>

using namespace std;

class Player1
{
    private:
        int _health;
        int _power;

    public: 
        // Default parameter.
        Player1(int health = 100, int power = 50)
        {
            _health = health;
            _power = power;

            cout << "Player " << _health <<", " << _power << endl;
        }
};

void player1_main()
{
    cout << "Player1" << endl;
    Player1 player0(100, 50);
    Player1 player1 = Player1(300, 150);
    Player1* player2 = new Player1(400, 250);

    Player1 player3;
    Player1 player4 = Player1();
    Player1* player5 = new Player1();

    //It only initialize health.
    Player1 player6(300);

    delete player2;
    delete player5;
}
