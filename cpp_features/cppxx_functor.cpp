/* a functor is functional object in old C++. the functor has overloaded operator()()
currently all people use lambda expressions instead.
$ g++ -std=c++17 cppxx_functor.cpp -o main.exe && ./main.exe

Aleksander Czastuchin
2019, lato
*/
#include <iostream>
#include <array>
#include <type_traits>
#include <algorithm>

using std::cout;
using std::array;
using std::boolalpha;
#define nl '\n'

struct functor
{
    bool operator()(const long& var) const
    {
        return var > 0;
    }
};

int main()
{
    const short size = 3;
    using type = array<long, size>;
    type numbers_to_check = { -100, 100, 300 };

    cout << "how much positive numbers is?" << nl;
    const short grether_than_zero = std::count_if
    (
        numbers_to_check.begin(), 
        numbers_to_check.end(),
        functor()
    );

    cout << grether_than_zero << nl;

    // testing the functor
    functor f;
    f(100);
    f.operator()(200);

    const bool is_invocable = std::is_invocable<functor()>::value;
    cout << "is_invocable = " << boolalpha << is_invocable << nl;

}