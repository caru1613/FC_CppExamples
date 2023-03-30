#include <iostream>
#include "MoveString.h"
#include "NotMoveString.h"


template<typename T>
void swapCopy(T& x, T& y)
{
    T temp = x; // 임시 객체에 복사하는 비용
    x = y;
    y = temp;
}


template<typename T>
void swapMove(T& x, T& y)
{
    T temp = std::move(x); // 강제로 이동,
    x = std::move(y);
    y = std::move(temp);
}

int main()
{
    NotMoveString nms0("abc");
    nms0 = NotMoveString("def"); // 복사 비용 발생


    MoveString  ms0("abc");
    ms0 = MoveString("def"); // 복사 비용 발생 하지 않음, 이동
    MoveString ms1("def");
    ms0 = ms1;  // 이동하지 않고 복사, ms1 이 이후에 사용될 수 있기 때문

    swapCopy(ms0, ms1);
    swapMove(ms0, ms1);

    return 0;
}

#if 0
#include <iostream>
#include <vector>
#include "MoveString.h"


MoveString makeString(const char* str)
{
    return MoveString(str); // 이곳에 복사가 일어날 것으로 예상하여 std::move를 사용하지 말자. RVO 최적화
}

int main()
{
    std::vector<MoveString> s{ MoveString("abc") };
    std::cout << "resize" << std::endl;
    s.reserve(100); // MoveString의 이동 관련 함수들의 noexcept 를 삭제하는 경우 복사 발생


    makeString("abc");


    int num0 = 10;
    int& num1 = num0;
    int&& num2 = num0 + num1; // 임시 값을 받을 수 있다

    //int& num3 = 3; // 임시 값을 받을 수 없다
    //int&& num4 = num0; // 임시 값이 아니기 때문에 받을 수 없다
    //int&& num5 = num1; // 임시 값이 아니기 때문에 받을 수 없다

    int& num6 = num2; // r-value reference 는 l-value 이기 때문에 받을 수 있다
    //int&& num7 = num2; // r-value reference 는 l-value 이기 때문에 받을 수 없다
    int&& num8 = std::move(num0);

}
#endif
