/*
bite operations in C++
look at my code. I used bite operations to write and read an ip address to/from
integer. this approuch uses in game protocols to save package's traffic.
g++ -std=c++17 bit_operations.cpp -o main.exe && ./main.exe


Aleksander Czastuchin
2019, lato, july
*/
//#include <cstdio>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

#define bits(x) std::bitset<sizeof(x) * 8>(x)
#define uint32 unsigned

uint32 set_ip_address(uint32 one, uint32 two, uint32 three, uint32 four)
{
    uint32 ip = 0;
    cout << std::hex;
    //cout << bits(ip) << endl;
    //cout << bits(255) << endl;

    ip = ip | (one << 8 * 3);
    ip = ip | (two << 8 * 2);
    ip = ip | (three << 8 * 1);
    ip = ip | four;

    cout << bits(ip) << endl;
    return ip;
}

void print_ip_address(const uint32& ip)
{
    cout << std::dec;
    uint32 mask = 0;
    mask = mask | 255;
    //cout << bits(mask) << endl;
    for (short i = 3; i >= 0; i--)
    {
        //cout << bits((ip >> 8 * i)) << endl;   
        cout << static_cast<short>((ip >> 8 * i) & mask) << '.';
    }
}

int main()
{
    auto&& ip = set_ip_address(255, 200, 150, 50);
    print_ip_address(ip);
    return 0;

}