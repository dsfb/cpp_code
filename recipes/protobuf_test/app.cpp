#include "message.pb.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    package p;
    const char* name = "value\0\0\0\0\0\0\0\0\0\0";
    const short name_size = strlen(name);
    cout << "name has " << name_size << " characters" << endl;
    
    p.mutable_name()->assign(name, 16);
    //p.set_name(name);
    cout << p.DebugString() << endl;
    return 0;
}