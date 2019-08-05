/* you need write a polindrom function.
Palindrom – wyrażenie brzmiące tak samo czytane od lewej do prawej i od prawej do lewej.
 Przykładem palindromu jest: Kobyła ma mały bok

 Aleksander Czastuchin
 2017
 g++ -std=c++17 palindrome.cpp -o main.exe
  */
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

bool isPalindrome(const std::string& word)
{
    auto start = word.begin();
    auto end = --word.end();
    int s = word.size();
    unsigned short a, b;

    for (int i = 0; i <= s; i++)
    {
        a = *start;
        b = *end;
        //  D(68) = d(100)
        // a == a     a == A         A == a
        if (a == b || a == b - 32 || b == a - 32)
            continue;
        else return false;
	    
        start++;
        end--;
    }
    return true;
}


int main()
{
	char a = 'D';
	char b = 'd';
	auto r = (int)a - (int)b;
	cout << r << endl;
    cout << boolalpha;
	cout << isPalindrome("Deleveled");
	return 0;
}
