/*
there is small example of using concepts that are appeared in c++20 standard.

there are two new keywords:
concept <name> - describes the type of the future concept
requires - rescribes requirements or constraints

co compile and run:
clear && g++ --std=c++20 -o main cpp20_concept.cpp && ./main
gcc version 10.0.1 20200411 (experimental)


the author:
Oleksandr Chastukhin
*/
#include <type_traits>
#include <concepts>
#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

struct non_player_characher {};
struct player
{
    bool is_online;

    operator bool()
    {
        return is_online;
    }
};

/*
in the code below I created an concept that verifies whether an instance
of the type 'type' is convertable to the type 'bool'
*/
template <typename type>
concept can_be_online = requires (type instance) {

    { instance } -> std::convertible_to<bool>;
};


/*
and then I wrote the below finction to test if the game object is online
*/
template<can_be_online type>
bool check_online(type game_object)
{
    return game_object; // operator bool() works
}


int main()
{
    player p;
    p.is_online = true;

    non_player_characher npc;

    cout << boolalpha;
    cout << check_online(p) << endl;

    /*
    error: use of function ‘bool check_online(type) 
    [with type = non_player_characher]’ with unsatisfied constraints
    */
    cout << check_online(npc) << endl;


    return 0;
}