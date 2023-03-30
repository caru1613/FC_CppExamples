#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;


template<typename T>
struct is_pointer
{
    static const bool value = false;
};

template<typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};

template<typename T>
void foo(T t)
{
    cout << is_pointer<T>::value << endl;
}


template<typename T>
struct remove_pointer
{
    using type = T;
};

template<typename T>
struct remove_pointer<T*>
{
    using type = T;
};

template<typename T>
struct add_pointer
{
    using type = T*;
};

template<typename T>
struct add_pointer<T&>
{
    using type = T*;
};

int main()
{
    cout << std::boolalpha;
    {
        // 컴파일 타임의 타입에 관련된 기능을 제공
        /*  std::is_pointer
            true
            false
        */
        cout << "std::is_pointer" << endl;
        cout << std::is_pointer<int*>::value << endl;
        cout << std::is_pointer<int>::value << endl;

        /*
           is_pointer
           true
           false
        */
        cout << "is_pointer" << endl;
        cout << is_pointer<int*>::value << endl;
        cout << is_pointer<int>::value << endl; // 템플릿 특수화로 인해 true

        int num = 0;
        int* pNum = &num;
        /*
            foo()
            false
            true
        */
        cout << "foo()" << endl;
        foo(num);
        foo(pNum);
    }
    {
        /*
            add remove is pointer
            true
            false
            false
        */
        cout << "add remove is pointer" << endl;
        int num = 0;
        std::add_pointer<int>::type pNum = &num;
        foo(pNum); // true 

        std::remove_pointer<int*>::type n = *pNum;
        foo(n); // false

        cout << is_pointer<remove_pointer<int*>>::value << endl; // false
    }
    {
        cout << "typeid()" << endl;
        int i;
        int* p;
        int** pp;
        int& r = *p;
        cout << typeid(i).name() << endl;
        cout << typeid(p).name() << endl;
        cout << typeid(pp).name() << endl;
        cout << typeid(r).name() << endl;

        /*
            add pointer type
            Pi
            PPi
            Pi
        */
        cout << "add pointer type" << endl;

        add_pointer<int>::type num0;
        cout << typeid(num0).name() << endl;

        add_pointer<int*>::type num1;
        cout << typeid(num1).name() << endl;

        add_pointer<int&>::type num2; // 특수화
        cout << typeid(num2).name() << endl;
    }
}

#if 0
#include <iostream>

using std::cout;
using std::endl;


enum Unscoped
{
    A, B
};


enum class Scoped : long long
{
    A, B = 10000000000
};


template<typename T>
struct is_scoped_enum
{
    // enum 인데 int로 변환이 되지 않으면 Scoped
    static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
};

// SFINAE(Substitution failure is not an erro) 이용
template<typename T, typename std::enable_if<is_scoped_enum<T>::value, int>::type = 0>
std::ostream& operator<<(std::ostream& os, const T& value)
{
    // underlying_type  을 통해 타입을 알아냄
    using t = typename std::underlying_type<T>::type;
    cout << static_cast<t>(value);
    return os;
}

int main()
{
    cout << std::boolalpha;

    cout << A << endl;
    cout << static_cast<int>(Scoped::B) << endl; // overflow

    cout << static_cast<std::underlying_type<Scoped>::type>(Scoped::B) << endl;
    cout << Scoped::A << endl;
    cout << Unscoped::B << endl;
}

#endif
