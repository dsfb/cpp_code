/* this this code I am testing to use std::unique_ptr

g++ -std=c++17 unique_ptr.cpp -o main.exe && ./main.exe
file:///D:/html_book_20190607/reference/en/cpp/memory/unique_ptr.html
Aleksander Czastuchin
2019
 */
#include <memory>
#include <iostream>

#define nl '\n'
using namespace std;

struct type
{
    type()
    {
        cout << "type()" << nl;
    }
    ~type()
    {
        cout << "~type()" << nl;
    }

    constexpr const static char* her_name = "Linda";
};

int main()
{
    using ptr_type = unique_ptr<type>;
    {
        auto ptr = make_unique<type>(); // c++14
        if (ptr) {
            cout << "the address is " << hex << &*ptr << nl;
            ptr.reset(); // call ~test()
            cout << "the address is " << hex << &*ptr << nl; // 0
        }
    }

    cout << nl;

    {
        ptr_type ptr1 = nullptr;
        {   
            auto ptr2 = make_unique<type>();

            // how to get an address 
            cout << hex << ptr2.get() << nl;
            cout << hex << &*ptr2 << nl;

            //unique_ptr& operator=(const unique_ptr&) = delete;
            // ptr1 = ptr2;
            
            // you cam only move it like this below
            //ptr1 = std::move(ptr2);
            //ptr2.reset();

            // or like this
            ptr1.reset(ptr2.release());

            if (ptr2 == nullptr)
                cout << "yes, it's null already" << nl;
        }

        // how to get a data
        cout << "her name is " << ptr1->her_name << nl;
        cout << "her name is " << (*ptr1).her_name << nl;
    }

    cout << nl;

    { 
        auto deleter = [](type* what){
            // you can specify here an actioin while deleting
            cout << "the lambda deleter is working" << nl;
            // the deleter must have delete operation!
            delete what;
        };

        cout << "unique ptr with deleter" << nl;
        auto ptr = unique_ptr<type, decltype(deleter)>(new type(), deleter);
    }

    cout << nl;

    {
        struct functor {
            void operator() (type* p) {
                std::cout << "the functor deleter is working" << nl;
                delete p;
            }
        };

        auto ptr = unique_ptr<type, functor>(new type(), functor());
    }
    return 0;
}