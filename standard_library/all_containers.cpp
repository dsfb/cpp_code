/*
++ -std=c++17 all_containers.cpp -o main && ./main
Aleksander Czastuchin
2019, summer
*/

#include <array>
#include <iostream>
#include <map>
#include <utility> // std::pair<,>
#include <vector>

using namespace std;

void std_pair_test()
{
    pair<int, int> p { 10, 20 };
    cout << p.first << '/' << p.second << endl;
    map<int, int> m;
    m.insert(std::move(p));
    cout << "m.size() = " << m.size() << endl;
}

void std_map_test()
{
    map<int, char> m;
    m.insert({ 1, 'a' });
    m.emplace(2, 'b');

    const bool is_here = m.find(1) != std::end(m);
    cout << boolalpha << is_here << endl;

    for (const auto& [key, value] : m)
        cout << key << '/' << value << endl;
}

void std_vector_test()
{
    using type = unsigned;
    vector<type> v = { 1, 2, 3, 4, 5 };
    v.push_back(6);
    v.emplace_back(7);

    for (const auto& i : v)
        cout << i << endl;

    cout << endl;
}

void std_array_test()
{
    using type = std::array<int, 2>;
    type a = { 1, 2 };
    const bool is_empty = a.empty();
    int first_element = a.at(0);
    a.size();

    for (const auto& i : a)
        cout << i << endl;

    cout << endl;
}

int main()
{
    // the dynamic array
    //std_vector_test();

    // c++11, std::array - static array
    //std_array_test();

    // std::map is key-value SORTED container
    // the key must have implemented opetator<
    //std_map_test();

    // it is a simple pair - key with its value. nothing special
    std_pair_test();

    return 0;
}