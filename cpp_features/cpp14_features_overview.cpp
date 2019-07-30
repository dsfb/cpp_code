/* I am going to show most important parts of c++14 standard 

g++ -std=c++14 cpp14_features_overview.cpp -o main && ./main
Aleksander Czastuchin
2019, summer

*/

#include <iostream>
#include <memory>

using namespace std;

template <typename type1, typename type2>
auto type_deduction_cpp11(type1 one, type2 two) -> decltype(one + two)
{
    return one + two;
}

template <typename type1, typename type2>
auto type_deduction_cpp14(type1 one, type2 two)
{
    return one + two;
}

constexpr int sum()
{
    int a = 10;
    int b = 20;
    return a + b;
}

int main()
{
    // c++11 type deduction
    cout << type_deduction_cpp11(2, 2.5) << endl;

    // c++14, auto type deduction;
    cout << type_deduction_cpp14(2, 2.5) << '\n';

    // c++14, generic lambda. you should not care about you pasted
    auto lambda = [](auto a) mutable { a = 0; };

    // c++14, user defiend captire variables
    // I can declare the lambda inside my cature list!
    auto wow = [value = []() -> int { return 2; }()](auto one) { return one + value; };

    // c++14, make_unique<>() function for smart pointers
    auto pointer = std::make_unique<char>();
    bool is_empty = pointer.get() == nullptr;
    cout << boolalpha << is_empty << endl;
    *pointer = { 'p' };
    cout << *pointer.get()
         << endl;

    // c++14, constexpr for variables
    cout << sum() << endl;

    return 0;
}