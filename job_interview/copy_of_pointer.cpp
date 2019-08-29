#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::string;

void copy_pointer(const char* p)
{
    // p is copy of original!
    string s = "abc";
    p = const_cast<char*>(&s.c_str()[1]);
    p++;
    cout << *p << '\n';
}

int main()
{
    {
        char c = 'a';
        char* p = &c;
        copy_pointer(p);
    }
    string s = "lavidaloca";
    auto p1 = s.c_str();
    const char* p2 = s.c_str();
    p2++;
    const char* const p3 = s.c_str();
    //p3++; // haha, I knew it!
    cout << *p2 <<'\n';
    return 0;
}