#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;

class boss;
#define is_boss(y) std::is_base_of_v<boss, decltype(y)>


struct creature
{
    virtual void attack(int damage) = 0;
};

struct boss : creature
{
    boss()
    { 
        cout << "boss()" << endl;
    }

    virtual void attack(int damage) override { 
        cout << "uahaha";
     }
};

template <typename ... types>
struct monster : types ...
{
    monster() : types() ...
    {
        cout << "monster()" << endl;
    }
};

int main()
{
    monster<boss> m;
    if (is_boss(m))
            m.attack(100);
    return 0;
}