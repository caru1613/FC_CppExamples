#include <iostream>

using namespace std;

struct Transaction
{
    const int txID;
    const int fromID;
    const int toID;
    const int value;

    class Builder
    {
    private:
        int _fromID;
        int _toID;
        int _value;

    public:
        Builder() : _fromID(0), _toID(0), _value(0)
        {
        }

        Transaction build()
        {
            int txID = _fromID ^ _toID ^ _value;
            return Transaction{txID, _fromID, _toID, _value};
        }

        Builder& setFromID(int fromID)
        {
            _fromID = fromID;
            return *this;
        }

        Builder& setToID(int toID)
        {
            _toID = toID;
            return *this;
        }

        Builder& setValue(int value)
        {
            _value = value;
            return *this;
        }

        int getFromID()
        {
            return _fromID;
        }

        int getToID()
        {
            return _toID;
        }
        
        int getValue()
        {
            return _value;
        }
    };
};

void buildTransaction()
{
    Transaction::Builder builder;
    cout << builder.getFromID() << " " << builder.getToID() << " " << builder.getValue() << endl;
    cout << endl;

    Transaction tx = builder.build();
    cout << tx.txID << " " <<  tx.fromID <<  " " << tx.toID << " " << tx.value << endl;
}
