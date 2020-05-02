/*
$ g++ -std=c++17 cppxx_function_alias.cpp -o main && ./main
Aleksander Czastuchin
2019, lato, lipiec
*/

#include <iostream>
#include <type_traits>

using namespace std;

// some function for tests
void print(int var = 0)
{
    cout << var << '\n';
}

// new c++
const auto alias = print;
using function_type = void(int);
using function_pointer = function_type*;

// old c++
typedef void (*function_pointer2)(int);

void call(void (*callable)(int))
{
    callable(50);
}

int main()
{
    void (*p1)(int) = print;
    p1(10);

    function_pointer p2 = print;
    p2(20);

    function_type* p3 = print;
    p3(30);

    alias(40);

    call(print);

    cout << boolalpha;
    cout << std::is_same_v<function_pointer, function_pointer2>; // true
    cout << endl;

    return 0;
}