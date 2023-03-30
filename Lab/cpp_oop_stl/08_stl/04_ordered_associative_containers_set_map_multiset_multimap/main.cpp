#include <iostream>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;

int main1(void);
int main2(void);

/*
main1()
m[1]: a
m[2]:
m0
1:1
2:2
3:3
m1
 
 */

int main1()
{
    cout << "main1()" << endl;
    // Key, Value, 트리 기반, 삽입 삭제 O(log n)
    std::map<int, std::string> m;
    m[1] = "a";

    cout << "m[1]: " << m[1] << endl;
    cout << "m[2]: " << m[2] << endl; // 첨자 연산 조회 시 Value가 없는 경우 Value의 기본 값이 나오게 됨

    cout << "m0" << endl;
    // map의 원소는 std::pair
    std::map<int, std::string> m0{
        {1, "1"},
        std::pair<int, std::string>(2, "2"),
        std::make_pair(3, "3")
    };

    // 항상 Key 값으로 정렬이 되어 있다
    for (const std::pair<int, std::string>& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    cout << "m1" << endl;
    std::map<int, std::string> m1;
    // 사실 상 pair는 std::pair<int, std::string> 이 아니라 std::pair<const int, std::string>
    // Tree에서 Key는 바뀌면 안 되기 때문
    for (const std::pair<int, std::string>& pair : m1) // 실제로 pair의 타입이 다르기 때문에 형변환이 일어남
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const std::pair<const int, std::string>& pair : m1) // 실제로 const가 있는 pair가 맞는 표현
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const auto& pair : m1) // 실수를 방지 하기 위해 auto를 사용
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    return 0;
}

/*
 main2()
map
true
3
10
success: false
iter->first: 3
iter->second: 10
10

[k, v]1:10
[k, v]1:20
[k, v]1:30
[k, v]2:10
10
20
30
40
Set
10
1
1
3
3
10
10
Set/Map sort
-1
3
10
10
3
-1
*/
int main2()
{
    cout << "main2()" << endl;

    cout << "Map" << endl;
    {
        cout << std::boolalpha;

        std::map<int, std::string> m;
        cout << "std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, \"10\" })" << endl;
        std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, "10" }); // 복잡하니까 auto 사용
        cout << "result.second: " << result.second << endl; // 성공 여부
        cout << "result.first->first: " << result.first->first << endl; // 해당 Key에 일치하는 map에 있는 iterator
        cout << "result.first->second: " << result.first->second << endl;

        // C++17부터
        cout << "auto [iter, success] = m.insert({ 3, \"20\" })" << endl;
        auto [iter, success] = m.insert({ 3, "20" });
        cout << "success: " << success << endl;
        cout << "iter->first: " <<  iter->first << endl;
        cout << "iter->second: " << iter->second << endl;

        // 이터레이터 찾기
#if 0
        cout << "find and erase with iterator." << endl;
        if (auto iter = m.find(3); iter != m.end())
        {
            cout << "iter->second: " << iter->second << endl; // 이터레이터로 지우기
            iter = m.erase(iter);
            cout << "iter->first: " <<  iter->first << endl;
            cout << "iter->second: " << iter->second << endl;

        }

        if (auto iter = m.find(3); iter != m.end())
        {
            cout << "iter->second: " << iter->second << endl; // 이터레이터로 지우기
            iter = m.erase(iter);
            cout << "iter->first: " <<  iter->first << endl;
            cout << "iter->second: " << iter->second << endl;

        }
#endif
        {
            bool ret;
            cout << "erase with key" << endl;
            ret = m.erase(3); // 키로 지우기
            cout << "ret: " << ret << endl;                  
        }
                            
        cout << endl;
    }
    cout << "Multimap" << endl;
    {
        // 중복 key 허용
        std::multimap<int, std::string> mm{
            {1, "50"},
            {1, "30"},
            {2, "400"},
            {1, "200"},
            {2, "100"},
        };

        for (const auto& [k, v] : mm)
        {
            cout << "[k, v]" << k << ":" << v << endl;
        }

        // 항상 성공
        //std::map<int, std::string>::iterator
        std::multimap<int, std::string>::iterator iter = mm.insert({ 1, "40" });
        cout << "multimap key: " << iter->first << endl;
        cout << "multimap value: " << iter->second << endl;

        // 경계
        cout << "Multimap lower_bound and upper_bound" << endl;
        auto lower = mm.lower_bound(1);
        auto upper = mm.upper_bound(1);
        cout << "lower->first : " << lower->first << endl;
        cout << "lower->second : " << lower->second << endl;
        cout << "upper->first : " << upper->first << endl;
        cout << "upper->second : " << upper->second << endl;
        //auto [lower, upper] = mm.equal_range(1); // 위와 같음
        for (auto iter = lower; iter != upper; ++iter)
        {
            cout << iter->second << endl;
        }
    }

    cout << endl;
    cout << "Set" << endl;
    {
        // 트리 구조. Key만 있음, 정렬 되어 있음
        std::set<int> s{
            1, 2, 3, 4
        };
        for (const auto& num : s)
        {
            cout << num << " ";
        }
        cout << endl;

        if (auto [iter, success] = s.insert(10); success)
        {
            cout << *iter << endl;
        }

        for (const auto& num : s)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    {
        // 트리 구조. Key만 있음, 정렬 되어 있음, 중복 허용
        std::multiset<int> ms{
            1, 1, 3, 10, 10, 3
        };
        for (const auto& num : ms)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Set/Map sort" << endl;
    {
        // std::less<int> 정렬을 어떻게 할지 결정하는 함수 객체
        std::set<int, std::less<int>> s;
        std::map<int, std::string, std::less<int>> m;

        std::set<int, std::less<int>> s0{ 3, 10, -1 };
        std::set<int, std::greater<int>> s1{ 3, 10, -1 };

        // 오름차순
        cout << "Sort with less<int>" << endl;
        for (const auto& num : s0)
        {
            cout << num << endl;
        }

        // 내림차순
        cout << "Sort with greater<int>" << endl;
        for (const auto& num : s1)
        {
            cout << num << endl;
        }
    }

    return 0;
}

int main()
{
    main1();
    main2();
}
