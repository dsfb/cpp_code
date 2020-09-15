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

#define nl '\n'
#define bits(x) std::bitset<sizeof(x) * 8>(x)
#define uint32 unsigned

// it changes decimal to binary
string to_binary(short decimal)
{
    string result;
    while(decimal > 0) {
        short if_modulo = (decimal % 2) > 0 ? 1 : 0;
        // bit order: from left to right
        // [new bit][old bit]
        result = to_string(if_modulo) + result; 
        decimal = decimal / 2;
    }

    return result;
}

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

    cout << bits(ip) << nl;
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
        cout << ((ip >> 8 * i) & mask) << '.';
    }

    cout << nl;
}

void print_ip_address_binary(const uint32& ip)
{
    cout << std::dec;
    uint32 mask = 0;
    mask = mask | 255;
    //cout << bits(mask) << endl;
    for (short i = 3; i >= 0; i--)
    {
        //cout << bits((ip >> 8 * i)) << endl;   
        cout << to_binary((ip >> 8 * i) & mask).c_str() << '.';
    }

    cout << nl;
}

int main()
{
    auto&& ip = set_ip_address(180, 200, 150, 50);
    print_ip_address(ip);
    print_ip_address_binary(ip);
    return 0;

}