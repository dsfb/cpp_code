/* my impelementation of  a determinant of matrix 
recursive approach
https://www.mathsisfun.com/algebra/matrix-determinant.html

Aleksander Czastuchin
rok 2019, lato, lipiec
g++ -std=c++17 matrix_determinant_recursive.cpp -o main.exe
*/
#include <array>
#include <iostream>
#include <list>

using std::array;
using std::boolalpha;
using std::cout;
using std::endl;
using std::list;

// this functio prints any matrix
template <typename... types>
void print_matrix(types... args)
{
    auto count = sizeof...(args);
    bool is_zero = count == 0;
    bool is_not_square = count % 2 != 0;

    if (is_zero && is_not_square)
        return;

    int size = (count == 4) ? 2 : count / 4;
    //cout << "size = " << size << endl;
    int line = 0;

    auto print_line = [&, size](const auto& arg) mutable {
        if (line == size) {
            line = 1;
            cout << endl;
        } else
            line++;

        cout << arg << ' ';
    };

    ((print_line(args)), ...);
    cout << endl;
}

template <typename... types>
void print_sub_matrix(types... args)
{
    auto count = sizeof...(args);
    bool is_zero = count == 0;
    bool is_not_square = count % 2 != 0;

    if (is_zero && is_not_square)
        return;

    int size = (count == 4) ? 2 : count / 4;
    cout << "size = " << size << endl;
    int line = 0;

    int ignored_row = 0;
    int ignored_column = 0;
    int row = 0;
    // kolumna - column  |ˈkɑːləm|
    int column = 0;

    auto print = [&](const auto& arg) {
        bool can_print = row != 0 && column != ignored_column;
        bool end_line = line == size;

        if (end_line) {
            line = 1;
            cout << endl;
            // zwiększam row jak osiągnę koniec linii
            // column = 0 na koczątku linii
            row++;
            column = 0;
        } else {
            ++line;
            ++column;
        }

        if (!can_print)
            return;

        cout << arg;
        //cout << '[' << row + 1 << '.' << column + 1 << ']';
        cout << ' ';
    };

    // print default matrix
    print_matrix(args...);

    // print sub matrixes
    for (int i = 0; i < size; i++) {
        line = 1;
        row = 0;
        column = 0;
        ignored_column = i;

        cout << "ignored = " << ignored_row + 1 << ignored_column + 1 << endl;

        // zagląda do wszystkich elementów
        ((print(args)), ...);
        cout << endl;
    }
    cout << endl;
}

// it is will be my second implementation
class matrix2 : public list<list<int>> {
};

template <typename type, int size>
class matrix : public array<array<type, size>, size> {
public:
    template <type row_number, typename... types>
    void set_row(types... args)
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
        for (int i = 0; i < this->size(); i++) {
            /* for (int k = 0; k < this->size(); k++)
            {
                const auto& row = this->operator[](i);
                const auto& column = row[k];
                cout << column << ' ';
            }*/

            for (const auto& e : this->operator[](i))
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
            is_ok = false;
            return 0;
        }

        // a11 a12
        // a21 a22
        // det2 = a11*a22 - a21*a12
        if (m->size() == 2) {
            is_ok = true;
            return m->el(1, 1) * m->el(2, 2) - m->el(2, 1) * m->el(1, 2);
        } else if (m->size() == 3) {
            // a11 a12 a12
            // a21 a22 a23
            // a31 a32 a33
            matrix<int, 2> one;
            matrix<int, 2> two;
            matrix<int, 2> three;
            one.set_row<0>(m->el(2, 2), m->el(2, 3));
            /*
            one.set_row<1, type>(m->el(3, 2), m->el(3, 3));
            auto det1 = one.determinant(is_ok);

            two.set_row<0, type>(m->el(2, 1), m->el(2, 3));
            two.set_row<1, type>(m->el(3, 1), m->el(3, 3));
            auto det2 = two.determinant(is_ok);

            three.set_row<0>(m->el(2, 1), m->el(2, 2));
            three.set_row<1>(m->el(3, 1), m->el(3, 2));
            auto det3 = three.determinant(is_ok);*/

            //return m->el(1, 1) * det1 - m->el(1, 2) * det2 + m->el(1, 3) * det3;
        }

        /*int matrix_size = m->size() - 1;
        vector < matrix<type, matrix_size> matrixes;
        int ignored = 1;
        for (int i = 1; i <= size(); i++)
        {
            for (int j = 1; j <= size(); j++)
            {
                matrix temp;
                temp.set(i, j, m->el(i, j));
            }
        }*/

        // a lot to do =)

        is_ok = false;
        return 0;
    }

private:
    type el(int row_index, int column_index)
    {
        auto& row = this->operator[](row_index - 1);
        // warning: out of range
        return row[column_index - 1];
    }

    void set(int row_index, int column_index, type value)
    {
        auto& row = this->operator[](row_index - 1);
        row[column_index - 1] = value;
    }
};

int main()
{
    /*matrix<int, 2> m;
    //m[1][1] = 4;
    m.set_row<0>(3, 8);
    m.set_row<1>(4, 6);
    //m.set_row<1>(1,2,3,4,5);
    m.print();

    bool is_ok = false;
    cout << "determinamt 2 = " << m.determinant(is_ok) << endl;
    cout << boolalpha << "is ok = " << is_ok;*/

    //print_matrix(1, 2, 3, 4);
    print_sub_matrix(
        11, 12, 13, 14,
        21, 22, 23, 24,
        31, 32, 33, 34,
        41, 42, 43, 44);

    return 0;
}