#include <iostream>
#include <vector>
#include <list>
#include "Ranges.h"

using std::cout;
using std::endl;


template<typename TIterator, typename T>
bool has(TIterator begin,TIterator end, T value)
{
    for (auto iter = begin; iter != end; ++iter)
    {
        if (*iter == value)
            return true;
    }
    return false;
}

int main()
{
    cout << __func__ << endl;
    {
        std::vector<int> v{ 1, 2, 3 };
        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        {
            cout << *iter << endl;
        }

        cout << "double" << endl;
        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        {
            *iter *= 2;
        }

        for (std::vector<int>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter)
        {
            //*iter = 10; // const_iterator 변경 불가능
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums0{ 1, 2, 3 };
        std::list<int> nums1{ 1, 2, 3 };

        std::cout << std::boolalpha;
        // 이터레이터를 통해 이종의 컨테이너에 대해 같은 코드를 사용
        std::cout << has(nums0.begin(), nums0.end(), 1) << endl;
        std::cout << has(nums1.begin(), nums1.end(), 4) << endl;
        std::cout << std::endl;
    }
/*
Ranges
6Ranges Ranges
6Ranges begin
N6Ranges8IteratorE Iterator

6Ranges end
N6Ranges8IteratorE Iterator

N6Ranges8IteratorE operator!=
N6Ranges8IteratorE operator*
0

N6Ranges8IteratorE operator++
N6Ranges8IteratorE operator!=
N6Ranges8IteratorE operator*
1

N6Ranges8IteratorE operator++
N6Ranges8IteratorE operator!=
N6Ranges8IteratorE operator*
2

N6Ranges8IteratorE operator++
N6Ranges8IteratorE operator!=
*/
    cout << "Ranges" << endl;
    {
        // Range based for loop 역시 이터레이터 인터페이스를 이용한다
        for (int num : Ranges(0, 3))
        {
            std::cout << num << endl;
        }
    }
}

int main2()
{

    cout << __func__ << endl;
// output iterator
// *iter = value
// cout

// input iterator
// value = *iter
// cin

// forward iterator
// - forward_list, unordered xxx
// ++ ÀüÁø ¹Û¿¡ ¾È µÊ

// bidirectional iterator
// - list, set, map, multiset, multimap
// ++, --

// random access iterator
// - array, vector, deque
// ++, --, +, -


// continguous access iterator (C++20)
// - array, vector
// ++, --, +, -, physical memory contiguous

    return 0;
}
