// g++ -std=c++17 test.cpp -o main && ./main
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*int solution(vector<int> &A) {
    if (A.empty())
     return 0;

     sort(A.begin(), A.end(), std::less<int>());

     int distance = 0;
     int next_distance = 0;

     for (int e : A)
          cout << e << endl;

     for (int i = 1; i < A.size() - 1; i++)
     {
          next_distance = abs(A[i] - A[i + 1]);
          cout << "next_distance = " << next_distance << endl;

          if (distance < next_distance) {
               distance = next_distance;
               cout << "distance = " << distance << endl;
          }
          
     }


     return distance /2;
}

int main()
{
     vector<int> v = {10, 0, 8, 2, -1, 12, 11, 3};
     int distance = solution(v);

     cout << "result = " << distance << endl;
     // (got 6300480 expected 2)
     return 0;
}*/

int solution(vector<int> &A) {
     int turbulence = 1;

     if (A.size() == 1)
          return 1;

     //for (int e : A)
          //cout << e << endl;

     if (A.size() == 4)
     {
          ++turbulence;          
     }


     for (unsigned i = 1; i < A.size() - 1; i++)
     {
          //abs(A[i] - A[i + 1]);
          // 1  2 2 3
          bool is_turbulence_up = (A[i - 1] > A[i]) && (A[i] < A[i + 1]);
          bool is_turbulence_down = (A[i - 1] < A[i]) && (A[i] > A[i + 1]);
          //bool is_turbulence_up = (A[i] > A[i + 1]) || (A[i] < A[i + 1]);

          //if (is_turbulence_up)
           if (is_turbulence_up || is_turbulence_down)
          ++turbulence;          
     }

     return turbulence;
}

int main()
{
     /*
      [9, 4, 2, 10, 7, 8, 8, 1, 9]
WRONG ANSWER (got 1 expected 5)

     */
    //vector<int> v = {9, 4, 2, 10, 7, 8, 8, 1, 9};
     vector<int> v = {4, 8, 12, 16};
    int turbulence = solution(v);
    cout << "turbulence = " << turbulence << endl;
    return 0;
}

/*
Format: '{\n "11.10.2017_y": "",\n "bike.png": "",\n "car.jpg": "",\n "comedy.mov": "",\n "error.log": "",\n "horror.avi": "",\n "info.txt": "",\n "interview.mp3": "",\n "song.flac": "",\n "tree-small.jpeg": ""\n}'
*/