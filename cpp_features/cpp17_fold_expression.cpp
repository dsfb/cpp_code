/*
I learn:
fold expression
variadic template
sizeof...()
template... types
unary/binary fold

g++ -std=c++17 cpp17_fold_expression.cpp -o main && ./main
-std=s++17
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html

Aleksander Czastuhin
2019 rok, koniec lipca
*/

#include <iostream>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

template <typename type = int, typename... types>
type sum(types... args)
{
    // format: ( cast-expression fold-operator ... )
    // the cast-expression shall contain an unexpanded parameter pack
    // fold-operator is + in this case
    // is unary right fold
    return (args + ...);
}

template <typename... types>
void print_all(types... args)
{
    // it returns count of elements
    cout << "sizeof... = " << sizeof...(args) << endl;
    (cout << ... << args) << endl;
}

template <typename type = int, typename... types>
void fill_array(types... args)
{
    const int size = sizeof...(args);
    bool is_empty = size == 0;

    if (is_empty)
        return;

    //type* array = new type(sizeof...(args));
    vector<type> array(sizeof...(args));

    int i = 0;
    ((array[i++] = args), ...);

    for (auto&& element : array)
        cout << element << endl;
}

template <typename type = int, typename... types>
void print_all_new_line(types... args)
{
    if (sizeof...(args) == 0)
        return;

    auto print = [](const type& a) { cout << a << endl; };
    (print(args), ...);
}

template <typename... types>
void print_all_new_line2(types... args)
{
    if (sizeof...(args) == 0)
        return;

    ([args]{ cout << args << endl; }(), ...);
}

int main()
{
    //cout << sum(5, 5);
    //print_all(1, 2, 3, 4, 5);
    //fill_array(1, 2, 3, 4, 5);
    //print_all_new_line(1, 2, 3, 4, 5);
    print_all_new_line2(1, 2, 3, 4, 5);
    return 0;
}