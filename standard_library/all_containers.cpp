/*
g++ -std=c++17 all_containers.cpp -o main && ./main
Aleksander Czastuchin
2019, summer
*/

#include <algorithm>
#include <any>
#include <array>
#include <cstring>
#include <initializer_list> // c++11
#include <iostream>
#include <list>
#include <map>
#include <set> // std::set<key> and std::multiset<key>
#include <tuple>
#include <utility> // std::pair<,>
#include <variant>
#include <vector>
#include <queue>
#include <cstddef> // std::byte
#include <bitset>
#include <string>

using namespace std;

void std_byte_test()
{
    auto byte_to_binary = [](byte source) {
        short decimal = static_cast<short>(source);
        bitset<8> bits = bitset<8>(decimal);
        return bits.to_string();
    };

    auto test_bit = [](byte source, short bit_number) {
        if (bit_number <= 0 && bit_number >= 8)
            return false;
        const byte mask = static_cast<byte>(0b00000001);
        return ((source >> bit_number) & mask) == byte{1};
    };

    const byte b = static_cast<byte>(0b11110111);
    cout << to_integer<short>(b) << " is " << byte_to_binary(b) << endl;

    // check the bits
    cout << "the 8th bit is here: ";
    if (test_bit(b, 7))
        cout << "yes" << endl;
    else cout << "no" << endl;

    cout << "the 4th bit is here: ";
    if (test_bit(b, 3))
        cout << "yes" << endl;
    else cout << "no" << endl;
}

void std_queue_test()
{
    queue<short> q;
    q.push(1);
    q.push(2);
    q.emplace(2);
    short first_in_queue = q.front();
    q.pop();
    cout << "first_in_queue = " << first_in_queue << endl; // 1
}

void std_tuple_test()
{
    {
        auto t1 = make_tuple<int, char, bool>(10, 'a', false);
        bool get_bool;
        std::tie(std::ignore, std::ignore, get_bool) = t1;
        cout << "get_bool = " << get_bool << endl;
    }

    auto t2 = []() -> tuple<int, char, bool> { return { 20, 'b', true }; }();
    auto [get_int, get_char, get_bool] = t2;
    cout << "get_int = " << get_int << endl;
}

void std_initializer_list_test()
{
    auto print = [](initializer_list<int> l) {
        vector<int> pack(l);

        for (const auto& e : pack)
            cout << e << ',';

        cout << '\n';
    };

    print({ 1, 2, 3, 4, 5 });
    print({ 1, 2, 3 });

    // wooooow
    auto what_is_it = { 1 };
    const bool is_init_list = std::is_same_v<
        decltype(what_is_it),
        initializer_list<int>>;

    cout << boolalpha;
    cout << is_init_list << endl;
}

void std_variant_test()
{
    variant<int, char, bool> v;
    v = 2019;
    v = 'a';
    v = true;

    const bool current_is_bool = std::holds_alternative<bool>(v);
    cout << "current_is_bool = " << boolalpha << current_is_bool << endl;

    if (current_is_bool)
        cout << std::get<bool>(v) << endl;

    const bool current_is_int = std::get_if<int>(&v) != nullptr;
    cout << "current_is_int = " << current_is_int << endl;
}

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
    //m.insert({ 1, 'a' }); // error: only unique keys
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

    struct plain_data {
        int a, b;
    } data;

    // look at this ;)
    memcpy(&data, v.data(), sizeof(data));
    cout << "data.a = " << data.a << endl;
    cout << "data.b = " << data.b << endl;
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

void std_set_test()
{
    using key = int;

    set<key> s;
    s.insert(10);
    s.insert(20);
    s.emplace(-1);

    const bool contains_10 = s.find(10) != std::end(s);
    const unsigned grether_that_zero = std::count_if(s.begin(), s.end(),
        [](const key& element) { return element > 0; });

    cout << boolalpha;
    cout << "set's size = " << s.size() << endl;
    cout << "it contains 10 = " << contains_10 << endl;
    cout << "grether_that_zero = " << grether_that_zero << endl;

    set<key> s2;
    s2.merge(s);

    for (const key& k : s2)
        cout << k << ", ";
}

void std_multiset_test()
{
    multiset<short> m;
    m.insert(-3);
    m.insert(-3);
    m.emplace(3);
    // Inserts a new element into the container
    // as close as possible to the position just before hint
    m.emplace_hint(m.begin(), 4);

    std::for_each(
        m.begin(),
        m.end(),
        [](const short& k) { cout << k << '\n'; });
}

void std_list_test()
{
    using type = short;
    list<type> l;

    auto push = [&l](const initializer_list<type>& from) {
        for (const type& what : from) {
            using push_method_ptr
                = void (list<type>::*)(const type&);
            push_method_ptr push_method = nullptr;
            if (what >= 0)
                push_method = &list<type>::push_back;
            else
                push_method = &list<type>::push_front;

            // fucking hardcore
            (l.*push_method)(what);
        }
    };

    auto print = [&l]() {
        std::for_each(
            l.begin(), l.end(),
            [](const type& e) {
                cout << e << ", ";
            });
        cout << '\n';
    };

    push({ -3, -2, -1, 1, 2, 3, 0 });
    print();
    l.sort();
    print();
}

void std_any_test()
{
    any one = 1;
    any two = true;
    auto three = make_any<char>('w');

    cout << boolalpha << endl;
    cout << one.has_value() << endl;
    cout << one.type().name() << endl;

    int* one_value = any_cast<int>(&one);
    if (one_value)
        cout << *one_value << endl;
}

int main(const int args_count, const char** args)
{
    // the dynamic array
    // + holds element in one memory space
    // + you can use memcpy(to, from, how much)
    //std_vector_test();

    // c++11, std::array - it is static array
    //std_array_test();

    // collection of key-value pairs, sorted by keys, keys are unique
    // the key must have implemented opetator<
    //std_map_test();

    // it is a simple pair - key with its value. nothing special
    //std_pair_test();

    // unia - union  |ˈjuːniən|
    // it is new generation of a union
    //std_variant_test();

    // is a lightweight proxy object that provides access
    // to an array of objects of one type
    //std_initializer_list_test();

    // the std::set contains a sorted set of unique key-objects
    //std_set_test();

    // collection of keys, sorted by keys
    //std_multiset_test();

    // list
    // + fast insert and remove
    // - no find() or contains() method
    //std_list_test();

    // any holds whatever you want
    ///std_any_test();

    // a fixed-size collection of heterogeneous values
    // like std::pair<> but can holds more values
    //std_tuple_test();

    //std_queue_test();
    std_byte_test();
    return 0;
}