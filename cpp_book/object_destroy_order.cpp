/*
consider this code. in what order run destructors?
the answer: stack order - last in, first out


Aleksander Czastuchin
2019, lato
g++ -std=c++17 object_destroy_order.cpp -o main
clang-format 7
*/
#include <cstdio>

class type {
public:
    type(char name)
        : _name(name)
    {
        printf("type(%c)\n", _name);
    }
    ~type()
    {
        printf("~type(%c)\n", _name);
    }

private:
    char _name;
};

int main()
{
    type one('a');
    type two('b');
    return 0;
    type three('c');
    /*
    the ouput is:
                     type(a)
                     type(b)
                     ~type(b)
                     ~type(a)
    */
}