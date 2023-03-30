#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String
{
private:
    char* _chars;

public:
    String(const char* chars) : _chars(new char[strlen(chars) + 1])
    {
        strncpy(_chars, chars, strlen(chars) + 1);
    }

    bool operator!() const
    {
        cout << "function name :" << __func__ <<  endl;
        return strlen(_chars) == 0;
    }

    bool operator||(bool b) const
    {
        cout << "function name :" << __func__ <<  endl;
        return strlen(_chars) > 0 || b;
    }

    bool operator&&(bool b) const
    {
        cout << "function name :" << __func__ <<  endl;
        return strlen(_chars) > 0 && b;
    }

    void print() const
    {
        cout << _chars << endl;
    }
};

bool func_true()
{
    cout << "function name :" << __func__ <<  endl;
    return true;
}

bool func_falsee()
{
    cout << "function name :" << __func__ <<  endl;
    return false;
}

// 논리 연산자 오버로딩은 주의해야한다
int main()
{
    String s("abcd");
    if (!s) // 된다
    {

    }
#if 0
    if (s) // 안 된다
    {

    }
#endif


    String s0("abc");
    cout << "value : ";
    s0.print();
    if (s0 || func_true()) // s0가 true로 평가 됐지만 func가 실행 된다. (Short-circuit evaluation 안 됨)
    {// s0, func()의 평가 순서 보장이 안 된다. (|| 를 오버로딩함으로서 시퀀스 포인트가 아니게 됨)
        cout << "!!" << endl;
    }

    if (s0 && func_true()) // s0가 true로 평가 됐지만 func가 실행 된다. (Short-circuit evaluation 안 됨)
    {// s0, func()의 평가 순서 보장이 안 된다. (|| 를 오버로딩함으로서 시퀀스 포인트가 아니게 됨)
        cout << "&&" << endl;
    }

    cout << "value : ";
    String s1("");
    s1.print();
    if (s1 || func_true())
    {
        cout << "||" << endl;
    }

    if (s1 && func_true())
    {
        cout << "&&" << endl;
    }
    // && 오버로딩도 || 오버로딩과 같은 문제점을 가지고 있다
}
