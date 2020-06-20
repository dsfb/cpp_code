/*
since c++11 you are allowed to put an instance of a class inside your union.
prior to c++11 you could add to an union only a plain data like struct with no 
constructors and desctructors or int, short and such like.
since c++17 we can substitute unions for std::variant<> class.

below there is an example that shows you how a server and client can talk with
each other with miscellaneous messages that was defined inside an union.

the command so that to compile it:
g++ -std=c++98 cpp11_union_allows_class.cpp -o main && ./main
*/
#include <iostream>
using namespace std;

enum message_type { one, two };

struct not_plain_data
{
    float some_data;
    not_plain_data(float from) : some_data(from) {}
    operator float() const { return some_data; }
};

#pragma pack(1)
typedef struct
{
    union
    {
        int one;
        double two;
        not_plain_data three; // since c++11
    } contents;
} message;
#pragma pack()


void server_receive(message_type type, message*& m)
{
    switch (type)
    {
    case one:
        {
            int* contents = reinterpret_cast<int*>(m);
            cout << *contents << endl;
        }
        break;
    
    case two:
        {
            double* contents = reinterpret_cast<double*>(m);
            cout << *contents << endl;
        }
        break;
    }

    delete m;
    m = 0;
}

message* client_send(message_type type)
{
    switch (type)
    {
    case one:
        {
            int* contents = new int(10);
            return reinterpret_cast<message*>(contents);
            break;
        }
    
    case two:
        {
            double* contents = new double(20.);
            return reinterpret_cast<message*>(contents);
            break;
        }
    }

    return 0;
}

int main()
{
    // the client side
    message_type type = two;
    message* m = client_send(type);

    // the server side
    server_receive(type, m);

    cout << sizeof(message) << endl; // 8 (c++98)
    return 0;
}