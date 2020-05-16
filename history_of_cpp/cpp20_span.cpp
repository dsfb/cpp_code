/*
https://en.cppreference.com/w/cpp/container/span

compile this code with
clear && g++ --std=c++20 -o main cpp20_span.cpp && ./main

the author:
Oleksandr Chastukhin
*/

#include <span>
#include <iostream>

using std::span;
using std::cout;
using std::endl;

// c99 or similar: the pointer to the first element and the length
namespace c99
{
    void print_out(char* first_element, short length)
    {
        *(first_element + (length - 1)) = '?';

        for (short i = 0; i < length; i++)
            cout << *(first_element + i) << ' ';
        cout << endl;
    }
}

// c++03: the reference to the array
namespace cpp03
{
    template <class type, short length>
    void print_out(type (&array) [length])
    {
        array[length - 1] = '?';

        for (short i = 0; i < length; i++)
            cout << array[i] << ' ';
        cout << endl;
    }
}


// c++20, std::span - it is struct with a poiner and length inside
namespace cpp20
{
    void print_out(span<char> array)
    {
        array.back() = '?';

        for (const auto& element : array)
            cout << element << ' ';
        cout << endl;

        //cout << endl;
        //cout << std::boolalpha;
        //cout << "the size of the array is " << array.size() << endl;
        //cout << "bytes " << array.size_bytes() << endl;
        //cout << "it is empty " << array.empty() << endl;
    }
}

int main()
{
    const short length = 6;
    char package[length] = {'l', 'o', 'g', 'i', 'n', '\0' };

    c99::print_out(package, length);
    cpp03::print_out(package);
    cpp20::print_out(package);

    return 0;
}

/*

the output:

l o g i n ? 
l o g i n ? 
l o g i n ?

*/