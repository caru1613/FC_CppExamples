#include <iostream>
#include <string>

using namespace std;

int main()
{
    /* C++ style */
    {
        string s0 = "Hello";
        string s1 = "World";
        s0.append(s1); // append s1 to s0.
        cout << s0 << endl;

        s0 += s1;
        cout << s0 << endl;
    }
    
    /* C style */
    {
        char s2[100] = "Hello";
        char s3[] = "world";

        strcat(s2, s3);
        cout << s2 << endl;
    }

    return 0;
}
