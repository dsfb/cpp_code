/*
there is my small example explanes how to use std::optional. 
std::optional is template class and can hold or not hold some value.

running notes:
export PATH=$PATH:. && echo $PATH
g++ -std=c++17 cpp17_optional.cpp -o main &&  main && test $? -eq 0 && echo "success" || echo "some errors"

Aleksander Czastuchin
2019
*/
#include <optional>
#include <iostream>

using std::cout;
using std::optional;
using std::nullopt;
#define nl '\n'

enum class result_type { error, empty, has_value };

struct data {
    data(const data& source) = default;
    data(data&& source) = delete;
    data() = default;
    short number;

    // int -> data
    data& operator=(int from) {
        cout << "equals to " << from << nl;
        this->number = from;
        return *this;
    }

    // data -> short. wow!
    operator short() const {
        return number;
    }
};

optional<data> create(result_type state)
{
    switch (state) {
        case result_type::error:
            return nullopt;

        case result_type::empty:
            return std::make_optional<data>();

        case result_type::has_value:
            optional result = std::make_optional<data>(/* arguments if are */);
            if (result.has_value()) {
                cout << "has value" << nl;

                result.value() = 100; // way one
                result->number = 200; // way two
                (*result).number = 300; // way tree

                return result;
            }
    }

    return nullopt;
}


int main()
{
    auto result = create(result_type::has_value);
    if (result.operator bool()) {
        cout << "final value equals to " << result.value() << nl;
        return 0;
    }
    else return -1;

    return 0;
}