/*
I've decided to write quick implementation of the bubble sort algorithm.
I like to train myself. I remember as once I've written this algorithm at
university. It was long time ago. Well. I want to remember.

Aleksander Czastuchin
2019, summer
*/

#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;

void print_array(array<short, 10>& numbers)
{
    for (const auto n : numbers)
        cout << n << ',';

    //cout << '\n';
}

void bubble_sort(array<short, 10>& numbers)
{
    short iteration_count = 0;
    for (int k = numbers.size() - 1; k >= 0; --k) {
        for (int i = 0; i < k; i++) {
            //cout << "iteration nr " << ++iteration_count << endl;
            cout << numbers[i] << " and " << numbers[i + 1];
            if (numbers[i] > numbers[i + 1]) {
                cout << " -> ";
                short temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                print_array(numbers);
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    using type = short;
    array<type, 10> numbers = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    print_array(numbers);
    cout << '\n';
    bubble_sort(numbers);
    cout << '\n';
    print_array(numbers);
    return 0;
}
