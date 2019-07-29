/*
g++ -O3 -std=c++11  cpp11_recursive_lambda.cpp -o main && ./main
Aleksander Czastuchin
2019, lato, lipiec
*/
#include <functional>
#include <iostream>
using namespace std;

int main()
{
    function<void(int)> print;

    print = [&print](int arg) -> void {
        cout << arg << endl;
        if (--arg > 0)
            print(arg);
    };

    print(10);
    return 0;
}