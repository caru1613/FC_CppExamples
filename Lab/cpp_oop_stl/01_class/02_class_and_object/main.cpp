#include <iostream>

using namespace std;

class Player0
{
    //It is private as default.
    int health;
    int power;
};

class Player1
{
    public:
        int health;
        int power;
};

class Player2
{
    public:
        int health;
    private:
        int power;
};

class Player3
{
    public:
        int _health;
        int _power;
        string _name;
        
    public:
        void attach(Player3& target)
        {
            cout << "Attach " << _name << " ->" << target._name << endl;
            target.damaged(_power);
        }
        void damaged(int power)
        {
            _health -= power;
            if (_health <= 0)
                cout << "Dead." << _name << endl;
        }
};

class Player4
{
    private:
        int _health;
        int _power;
        string _name;
    public:
        Player4(int health, int power, string name)
        {
            _health = health;
            _power = power;
            _name = name;
        }

        void attack(Player4& target)
        {
            cout << "Attack " << _name << "->" << target._name << endl;
            target.damaged(_power);
        }

        void damaged(int power)
        {
            _health -= power;
            if (_health <= 0)
                cout << "Dead." << _name << endl;
        }
};

int main()
{
    {
        //Player0 player0{100, 200};
        //Player0 player0;
        //Player0.health = 100;
    }

    {
        Player1 player1{100, 200};
        player1.health = 200;
    }

    {
        Player2 player2;
        // player2.power = 200;
    }

    {
        cout << "Player 3" << endl;
        Player3 david {200, 100, "David" };
        Player3 daniel {200, 100, "Daniel" };
        daniel._health -= 100;
        daniel._health -= 100;
    }

    {
        cout << "Player 4" << endl;
        Player4 david{ 200, 100, "David" };
        Player4 daniel{ 200, 100, "Daniel" };

        // daniel._health -= 300;
        david.attack(daniel);
        david.attack(daniel);
    }

    return 0;
}
