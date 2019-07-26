/*
I learn:
fold expression
variadic template
sizeof...()
unary fold

-std=s++17
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html
*/

#include <iostream>

using std::cout;
using std::endl;

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
    if (sizeof...(args) == 0)
        return;

    type* array = new type(sizeof...(args));
    int i = 0;
    ((array[i++] = args), ...);

    delete[] array;
}

int main()
{
    //cout << sum(5, 5);
    //print_all(1, 2, 3, 4, 5);
    fill_array(1, 2, 3, 4, 5);
    return 0;
}