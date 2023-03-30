#include <iostream>
#include <vector>
#include <map>
#include <type_traits>

using std::cout;
using std::endl;

class Person {};
int func(float) { return 0; }

template<typename T, typename S>
void add0(T t, S s)
{
    auto r = t + s;
    std::cout << r << std::endl;
}

template<typename T, typename S>
auto add1(T t, S s) -> decltype(t + s) // C++14부터 생략가능
{
    return t + s;
}

enum class Type
{
    A, B
};

template<typename Enumeration>
auto asInteger(Enumeration value) -> typename std::underlying_type<Enumeration>::type // C++14부터 생략가능
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

int main1()
{
    auto i = 10; // int 형, 컴파일 타임 추론, 템플릿의 타입추론과 거의 같음
    auto j = 1u; // unsigned int


    std::vector<int> v;
    std::vector<int>::iterator iter0 = v.begin();
    auto iter1 = v.begin();  // 이 경우는 가독성에서 유리하다. 위의 경우 타입이 너무 장황함

    Person* person0 = new Person;
    auto person1 = new Person; // 좌변의 Person을 생략하여 중복되지 않는다.

    std::map<int, int> m;
    for (const std::pair<int, int>& pair : m) {} // 순회가 되지만 올바르지 않음, 임시 객체(pair)가 생성 됨
    for (const std::pair<const int, int>& pair : m) {} // 올바른 타입. key is const.
    for (const auto& pair : m) {} // auto 사용 시 key 값을 신경쓰지 않아도 됨. 실수가 줄어듬


    const int a = 10;
    const int& b = a;
    const int* c = &a;

    auto aa = a; // int
    auto bb = b; // int, 참조로 추론되지 않고 값으로 추론 됨
    auto cc = c; // const int*

    auto& dd = b; // const int&, const int로 추론 되고 &추가
    auto* ee = c; // const int*, const int로 추론 되고 *추가

    const auto& ff = b; // const int&, int로 추론 되고 const, & 추가

    int nums[] = { 1, 2, 3 };
    auto num0 = nums; // int*
    auto& nums1 = nums; // int(&)[3]

    //int func(float) { return 0; }
    auto func0 = func; // int (*)(float)
    auto& func1 = func; // int (&)(float)

    add0(1, 1.2);
    add1(1, 1.2);

    asInteger(Type::A);

    return 0;
}

template<auto N0, auto N1> // C++17부터
auto add()
{
    return N0 + N1;
}

template<auto... Args>
auto sum()
{
    return (Args + ...); // C++17부터
    // Args + ... : (A[0] + (A[1] + (A[2] + ... (A[n - 1] + A[n])
    // ... + Args : (A[0] + A[1]) + A[2]) + A[3]) + ... A[n])
    // Args + ... + B : (A[0] + (A[1] + (A[2] + ... (A[n - 1] + (A[n] + B)
    // B + ... + Args : (B + A[0]) + A[1]) + A[2]) + A[3]) + ... A[n])
}

class Person2
{
public:
    float weight;
    float height;

    void func() {}
};

int main2()
{
    std::cout << add<10, 2>() << std::endl;
    std::cout << add<10, 200000000000>() << std::endl;

    std::cout << sum<1, 2, 3>() << std::endl;
    std::cout << sum<10000000000000, 200000000000000, 3000000000000000>() << std::endl;

    std::map<int, std::string> m{
        {1, "1"}
    };

    {
        // structured binding
        const auto& [key, value] = *m.begin();
        std::cout << key << std::endl;
        std::cout << value << std::endl;

        int nums[]{ 1, 2, 3 };
        auto [x, y, z] = nums;

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;

        nums[0] = 0;

        std::cout << x << std::endl;

        std::tuple<int, float, std::string> t0{ 1, 2.0f, "3" };
        auto t1 = std::make_tuple(1, 2.0f, "3"); // 간결

        int x0;
        float y0;
        std::string z0;
        std::tie(x0, y0, z0); // 장황하고 불편...

        auto [x1, y1, z1] = t1; // 편함

        Person2 p{ 64.f, 172.f };
        auto [weight, height] = p; // 간결
    }

    return 0;
}


int main()
{
    cout << "main1()" << endl;
    main1();
    cout << endl;
    cout << "main2()" << endl;
    main2();
    return 0;
}
