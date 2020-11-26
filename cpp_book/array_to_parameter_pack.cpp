/*
the problem:
how to convert the array to parameter pack?

g++ -std=c++17 main.cpp -o main && ./main

Aleksander Czastuchin
*/

#include <iostream>
#include <type_traits>
#include <utility>
#include <functional>
#define nl '\n'

//template <typename type, unsigned size>
//using array_type = type (&)[size];

using namespace std;

template <typename type, int size, std::size_t ... index>
void take_argument_pack(type (&array) [size], std::index_sequence<index...>)
{
     auto printer = [](const auto& var) {
          cout << var << nl;
     };
    (printer(array[index]), ...);
}

template <typename type, int size, typename sequence = std::make_index_sequence<size>>
void take_array(type (&array) [size])
{
     auto s = sequence{};
     cout << "sequence size = " << s.size() << nl;
     take_argument_pack(array, s);
}


int main()
{
     int name[] = {1, 2, 3, 4, 5, 6};
     const short size = sizeof(name) / sizeof(*name);
     cout << "array size = " << size << nl;
     take_array<int, size>(name);
     return 0;
}