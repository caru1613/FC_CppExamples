#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

using std::cout;
using std::endl;

// 함수 객체
//struct Func
class Func
{
public:
    int operator()(int value) const
    {
        return value;
    }
};

int main1()
{
    cout << __func__ << endl;
    {
        Func func;
        cout << func(10) << endl;

        // lambda 객체
        auto func_lambda_0 = []()
        {
            return 10;
        };
        cout << func_lambda_0() << endl;

        int num = 1;
        auto func_lambda_1 = [num](int value) // num이 캡쳐 됨
        {
            return num + value;
        };
        cout << func_lambda_1(10) << endl;
    }
    {
        // algorithm의 find 사용
        std::vector<int> v{ 1, 2, 3, 4 };

        if (std::vector<int>::iterator iter = std::find(v.begin(), v.end(), 1); iter != v.end())
        {
            cout << *iter << endl;
        }
        cout << endl;

        if (auto iter = std::find(v.begin(), v.end(), 2); iter != v.end())
        {
            cout << *iter << endl;
        }
        cout << endl;

        if (auto iter = std::find(v.begin(), v.end(), 3); iter != v.end())
        {
            cout << *iter << endl;
        }
        cout << endl;

        if (auto iter = std::find(v.begin(), v.end(), 4); iter != v.end())
        {
            cout << *iter << endl;
        }
        cout << endl;

        // 멤버 함수의 find 사용
        std::set<int> s{ 1, 2, 3, 4};
        if (auto iter = s.find(4); iter != s.end())
        {
            cout << *iter << endl;
        }
        cout << endl;
        // 멤버 함수가 있는 경우는 멤버 함수를 사용하자


        // find_if 는 set에도 멤버 함수가 없다. 
        {
            auto iter = std::find_if(s.begin(), s.end(), [](const int& value) {
                return (value % 2 == 0);
                });
            if(iter != s.end())
            {
                cout << *iter << endl;
            }
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}

int main2()
{
    cout << __func__ << endl;

    cout << "vector" << endl;
    std::vector<int> v{ 1, 2, 3, 4, 3, 2, 1 };
    // 실제로 지우지 않고 지워야 하는 원소들만큼 앞으로 당긴다, 사이즈는 그대로
    // 1, 3, 4, 3, ?, ?
    for ( int n : v )
    {
        cout << n << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    auto iter = std::remove(v.begin(), v.end(), 2);
    for ( int n : v )
    {
        cout << n << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    // erase 를 해야 지워진다
    v.erase(iter, v.end());

    for (auto num : v)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    // remove 가 범용적이어야 하기 때문에 array 등에도 사용해야한다
    // array 경우 정적 배열이기 때문에 사이즈를 조절할 수 없음

    cout << "list" << endl;
    std::list<int> l{ 1, 2, 3, 4, 3, 2, 1 };
    l.remove(2); // list는 멤버 변수로 가지고 있고 erase 까지 한다.

    for (auto num : l)
    {
        cout << num << " ";
    }
    cout << endl;

    std::set<int> s{ 1, 2, 3, 4, 3, 2, 1 };
    //std::remove(s.begin(), s.end(), 2);  // 안 됨
    cout << endl;
    return 0;
}

int main()
{
    main1();
    main2();

    return 0;
}
