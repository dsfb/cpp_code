/*
there is quick sort algorithm. 
I habe been implementing....
g++ -std=c++17 quick_sort.cpp -o main
http://www.algorytm.edu.pl/algorytmy-maturalne/quick-sort.html

Aleksander Czastuchin
2019
*/

#include <array>
#include <cmath>
#include <iostream>

using std::array;
using std::cout;
using std::endl;
using uint16 = unsigned short;
using array_type = array<uint16, 10>;

void print_array(array_type& numbers)
{
    for (const auto n : numbers)
        cout << n << ',';

    cout << '\n';
}

void quick_sort(array_type& data, uint16 start, uint16 end)
{
    if (abs(start - end) <= 1)
        return;

    auto swap = [](auto& a, auto& b) mutable {
        auto temp = a;
        a = b;
        b = temp;
    };

    const uint16 pivot_index = start + (abs(end - start) / 2);
    uint16 pivot = data[pivot_index];

    cout << "pivot value = " << pivot << endl;
    cout << "pivot index = " << pivot_index << endl;

    uint16 left_side = start;
    uint16 right_side = end;

    for (int i = start; i < end; i++) {
        if (i < pivot_index && data[i] > pivot) {
            swap(data[i], data[right_side]);
            --right_side;
        }
        if (i > pivot_index && data[i] < pivot) {
            swap(data[i], data[left_side]);
            ++left_side;
        }

        if (i == start)
            cout << '[';
        cout << data[i] << ',';
        if (i == end - 1)
            cout << ']';
    }
    cout << endl;
    return;
    quick_sort(data, start, pivot_index);
    quick_sort(data, pivot_index, end);
}

int main()
{
    array_type numbers = { 10, 1, 8, 7, 6, 5, 4, 3, 2, 9 };
    print_array(numbers);
    quick_sort(numbers, 0, 9);
    print_array(numbers);
    return 0;
}