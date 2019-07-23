/*
dereferencing an invalid pointer

result
1) after delete will print 0
2) when the pointer is nullptr will segmentation fault

Aleksander Czasuchin
g++ -std=c++17 dereferencing_invalid_pointer.cpp  -o main
clang-format 7
*/
#include <cstdio>

void set_pointer(int*& pointer)
{
    int a = 10;
    pointer = &a;
    pointer = new int(10);
    delete pointer;
}

int main()
{
    int* pointer;
    int* pointer2 = nullptr;
    set_pointer(pointer);
    printf("%i", *pointer); // prints 0
    printf("%i", *pointer2); // segmentation fault
}