
/*
you need write a function that, given an array of integers/ 
and returns the smallest positive integer /
(greater than 0)/ that does not occur in vector

Aleksander Czastuhin
2019
*/
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int solution(vector<int> &A)
{
    if (!A.size())
        return 0;
    
    int smallest = A[0];
    
    for (auto elem : A)
    {
        if (/*elem > 0 &&*/ smallest > elem)
        smallest  = elem;
    }
    
    // if smallest holds in vector
    // if smallest les than zero
    while (std::find(std::begin(A), std::end(A), smallest) != std::end(A) || smallest <= 0)
    {
        smallest++;
    }
    
    return smallest;
}

int main()
{
    vector<int> a = {-5, -4, -3, -2, 0, 2, 3, 4 , 5};
    // get smallest positive that does not occurs
    solution();
    return 0;
}
