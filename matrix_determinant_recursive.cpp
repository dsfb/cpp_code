/* my impelementation of  a determinant of matrix 
recursive approach
https://www.mathsisfun.com/algebra/matrix-determinant.html

Aleksander Czastuchin
rok 2019, lato, lipiec
g++ -std=c++17 matrix_determinant_recursive.cpp -o main.exe
*/
#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;
using std::boolalpha;

template <typename type, int size>
class matrix : public array<array<type, size>, size>
{
public:

    template <type row_number, typename ... types> 
    void set_row(types ... args)
    {
        // show me count of given arguments
        ///cout << sizeof...(args) << endl;

        if (sizeof...(args) != this->size()) {
            cout << "it is wrong size" << endl;
            return;
        }

        // fold expression it is amazing
        //(cout << ... << args) << endl;

        int i = 0;
        auto& row = this->operator[](row_number);
        ((row[i++] = args), ...);
    }

    void print()
    {
        for (int i = 0; i < this->size(); i++)
        {
            /* for (int k = 0; k < this->size(); k++)
            {
                const auto& row = this->operator[](i);
                const auto& column = row[k];
                cout << column << ' ';
            }*/

            for(const auto& e: this->operator[](i))
                std::cout << e << ' ';

            cout << endl;
        }
        
    }

    int determinant(bool& is_ok)
    {
        return determinant_recursive(this, is_ok);
    }

    //tempalate <typename type, typyname types>
    static int determinant_recursive(matrix* const m, bool& is_ok)
    {
        if (m->empty()) {
            is_ok - false;
            return 0; 
        }

        // a11 a12
        // a21 a22
        // det2 = a11*a22 - a21*a12
        if (m->size() == 2) {
            is_ok = true;
            return m->el(1,1)*m->el(2,2) - m->el(2,1)*m->el(1,2);
        }
        // a lot to do =)


        is_ok = false;
        return 0;
    }

    

private:
    type el(int row_index, int column_index) {
        auto& row = this->operator[](row_index -1);
        // warning: out of range
        return row[column_index -1];
    }
};

int main()
{
    matrix<int, 2> m;
    //m[1][1] = 4;
    m.set_row<0>(3, 8);
    m.set_row<1>(4, 6);
    //m.set_row<1>(1,2,3,4,5);
    m.print();

    bool is_ok = false;
    cout << "determinamt 2 = " << m.determinant(is_ok) << endl;
    cout << boolalpha << "is ok = " << is_ok;
    return 0;
}