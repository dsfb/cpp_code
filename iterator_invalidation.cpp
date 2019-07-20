/*
iterator of vector has invalidation when:
1) capacity changed (by using push_back() or insert() method whatever)

Aleksander Czastuchin
g++ -std=c++17 -o main.exe iterator_invalidation.cpp
 */
#include <iostream>
#include <vector>

using namespace std;


void vector_capacity() try
{
    vector<int> data { 1, 2, 3 };
    cout << boolalpha;
    auto old_capacity = data.capacity();
    auto it = data.begin();
    
    do {
        int last = data.back();
        data.push_back(++last);      
        //cout << *it;
    }
    while (data.capacity() == old_capacity);

    cout << "old_capacity is " << old_capacity << endl;
    cout << "new capacity is " << data.capacity() << endl;

    cout << "show me which elements you have" << endl;
    for(; it != end(data); it++)
        cout << *it << endl;

    cout << "real values is" << endl;
    for (auto&& value : data)
        cout << value << endl;

}
catch (...) 
{
    cout << "something went wrong" << endl;
}

int main()
{
    //vector_change_element();
    vector_capacity();
    return 0;
}