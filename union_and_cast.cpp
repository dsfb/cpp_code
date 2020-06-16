/*
g++ -std=c++98 union_and_cast.cpp -o main && ./main
*/
#include <iostream>
using namespace std;

enum message_type { one, two };

#pragma pack(1)
typedef struct
{
    union
    {
        int one;
        double two;
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

    cout << sizeof(message) << endl; // 8
    return 0;
}