#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    if (N < 0)
        return;
        
    for (int i = 1; i <= N; i++)
    {
        bool isDivisibleByTwo = (i % 2 == 0) ? true : false;
         bool isDivisibleByThree = (i % 3 == 0) ? true : false;
          bool isDivisibleByFive = (i % 5 == 0) ? true : false;
          string answer;
          
        if (isDivisibleByTwo)
        {
            answer = "Codility";
        }
        if (isDivisibleByThree)
        {
            answer += "Test";
        }
        if (isDivisibleByFive)
        {
            answer += "Coders";
        }
        
        if (!answer.empty())
            cout << answer << endl;
            else 
        cout << i << endl;
    }
}
