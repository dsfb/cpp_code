/*
g++ -std=c++11 cpp11_features_overview.cpp -o main
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

template<typename type>
void print(type arg)
{
    cout << arg << endl;
}

template<typename type, typename ... types>
void print(type arg, types... args)
{
    cout << arg << endl;
    print(args...);
}

int main()
{
    // c++11, auto
    auto l = [](int a, int b){ return a + b; };
    auto result1 = l(2, 3); // int

    // c++11, ranged for loop
    vector<int> range {1,2,3,4,5};
    for (const auto & one : range)
        cout << one << endl;

    // c++11, lambdas
    int less_than_zero_count = 0;
    vector<int> numbers {0,0,-1, 2}; 
    std::for_each(numbers.begin(), numbers.end(),
    [&less_than_zero_count](int element) mutable -> void {
        if (element < 0)
         less_than_zero_count++;
    });
    cout << "less_than_zero_count = " << less_than_zero_count;
    cout << endl;

    // variadic templates
    print(1, 2, 3 ,4, 5);

    // std::unique_ptr
    { unique_ptr<int> ptr (new int (1000)); }

    // constexpr functions and variables
    // it allows compute a value in compile time
    constexpr int size = 10 + 15;
    int array[size];

    return 0;
}