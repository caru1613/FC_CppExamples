#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;

template <typename T>
void print(std::vector<T> vec)
{
    for (T n : vec)
    {
        cout << n << " ";
    }
    cout << endl;
}

template <typename T>
void print(std::deque<T> deq)
{
    for (T n : deq)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    {
        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        int* num = &vec[0];

        cout << "sizeof(vec) :" <<  sizeof(vec) << endl;
        cout << "vec.size() :" <<  vec.size()  << endl;
        cout << "vec.capacity() :" << vec.capacity() << endl;

        // vector의 사이즈가 크고 얼만큼 커질 지 알 수 있다면 reserve를 미리 해주자
        cout << "vec.reserve(vec.capacity() + 10)" << endl;
        vec.reserve(vec.capacity() + 10);

        cout << "sizeof(vec) :" <<  sizeof(vec) << endl;
        cout << "vec.size() :" <<  vec.size()  << endl;
        cout << "vec.capacity() :" << vec.capacity() << endl;

        // 둘의 주소가 다르다.
        cout << "Address of num: " << num << endl;
        //cout << "Address of vec: " << vec << endl; // It causes compile error.
        cout << "Address of &vec[0]: " << &vec[0] << endl;


        cout << " === vector === " << endl;
        print(vec);
        // 대체로 시간 복잡도 O(1), 재할당 될 때가 있으니 주의
        cout << "vec.push_back(10)" << endl;
        vec.push_back(10);
        print(vec);

        // 시간 복잡도 O(1)
        cout << "vec.pop_back()" << endl;
        vec.pop_back();
        print(vec);

        // 가장 앞에 삽입했기 때문에 O(n), 뒤로 다 밀림
        cout << "vec.insert(vec.begin(), 10)" << endl;
        vec.insert(vec.begin(), 10);
        print(vec);

        // [1, 2, 3, ?] 
        // size = 3
        // capacity = 4

        // push_back(4)
        // [1, 2, 3, 4]
        // size = 4
        // capacity = 4

        // push_back(5)
        // [1, 2, 3, 4, 5, ?, ?, ?] // 배열의 재할당
        // size = 4
        // capacity = 8
    }
    {
        cout << " === deque === " << endl;
        std::deque<int> nums;

        // 대체로 O(1)
        cout << "nums.push_front(1)" << endl;
        nums.push_front(1);
        print(nums);

        // 대체로 O(1)
        cout << "nums.push_back(2)" << endl;
        nums.push_back(2);
        print(nums);

        // 대체로 O(1)
        cout << "nums.push_front(3)" << endl;
        nums.push_front(3);
        print(nums);

        // 대체로 O(1)
        cout << "nums.push_back(4)" << endl;
        nums.push_back(4);
        print(nums);

        // push_back
        // [0]

        // push_front
        // [1] [0]
        // push_front 도 빠르게 만들기 위해서 배열을 더 만든다.
    }
}
