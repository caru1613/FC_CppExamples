#include <iostream>
#include <cstring>

using namespace std;

class String
{
    private:
        char * _str;

    public:
        String(const char* str)
        {
            int len = strlen(str);
            _str = new char[len + 1];
            strcpy(_str, str);
        }
        ~String()
        {
            delete [] _str;
        }

        void print()
        {
            cout << _str << endl;
        }
};

void stringfunc()
{
    String str("abc");
    str.print();
}
