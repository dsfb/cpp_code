/*
right-value reference
std::move()
std::forward()

g++ -std=c++17 cpp11_rvalue_reference.cpp -o main  && ./main
Aleksander Czastuchin
pią, 26 lip 2019, 16:30:32 CEST

*/
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

#define fwd(x) std::forward<decltype(x)>(x)

struct player {
    player() { cout << "player()" << endl; };
    player(const player& source)
    {
        cout << "player(const player&)" << endl;
        value = source.value;
    };
    player& operator=(const player& source) = delete;

    player(int v)
        : value(v)
    {
        cout << "player(int)" << endl;
    };

    player& operator=(const int& value)
    {
        cout << "player=(int)" << endl;
        this->value = value;
        return *this;
    }

    player(player&& source)
    {
        cout << "player(player&&)" << endl;
        value = source.value;
        source.value = 0;
    }

private:
    int value;
};

void take_value(player p)
{
    std::boolalpha(cout);
    //cout << std::is_lvalue_reference_v<decltype((var))> << endl;
    //cout << std::is_rvalue_reference_v<decltype((var))> << endl;
    p = 2;
}

void new_line()
{
    cout << endl;
}

template <typename type>
void add_player(type&& p)
{
    player new_player(fwd(p));
}

int main()
{
    // copy and move constructor
    /*
    player one = 1;
    take_value(one);
    newline();
    take_value(std::move(one));
    //*/

    // perfect forward
    // it helps to create objects without un-nece-sse-ry copies
    // by using only one function that takes all reference' type
    player two = 2;
    add_player(two);
    new_line();
    add_player(player());
    /*
                     player(int)
                     player(const player&)

                     player()
                     player(player&&)
    */
    return 0;
}