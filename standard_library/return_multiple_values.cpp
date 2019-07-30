/*
if I wanna return multiple values from the function, I will use
pair - for 2 values and tuple for 3+ values.
 * g++ -std=c++17 return_multiple_values.cpp -o main && ./main
 * Aleksander Czastuchin
 * 2019, summer
 * /
 */

#include <iostream>
#include <tuple> // since c++11
#include <utility> // std::pair<,>

using namespace std;

pair<bool, int> compute1()
{
    bool is_ok = true;
    int result = 10;
    return make_pair(is_ok, result);
}

//c++11, template< class... Types > class tuple;
std::tuple<bool, int> compute2()
{
    return { true, 10 }; // c++17
    //return std::make_tuple(true, 10);
}

int main()
{
    const auto& my_pair = compute1();
    cout << boolalpha;
    cout << "is ok = " << my_pair.first << endl;
    cout << "result = " << my_pair.second << endl;

    // c++17, structured binding
    //bool is_ok; // lol
    //int result; // haha
    auto [is_ok, result] = compute2();

    return 0;
}