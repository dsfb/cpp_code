/*
you need reprace numbers if ones can devide by 2, 3 and 5 
g++ -std=c++17 -O3 print_numbers_out.cpp -o main && ./main
Aleksanser Czastuchin
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void solution(int N)
{
    if (N <= 0)
        return;

    for (int i = 1; i <= N; i++) {
        bool isDivisibleByTwo = i % 2 == 0;
        bool isDivisibleByThree = i % 3 == 0;
        bool isDivisibleByFive = i % 5 == 0;
        string answer;

        if (isDivisibleByTwo) {
            answer = "isDivisibleByTwo";
        } else if (isDivisibleByThree) {
            answer += "isDivisibleByThree";
        } else if (isDivisibleByFive) {
            answer += "isDivisibleByFive";
        }

        if (!answer.empty())
            cout << answer << endl;
        else
            cout << i << endl;
    }
}

int main()
{
    for (int i = 1; i <= 10; i++)
        solution(i);
    return 0;
}
