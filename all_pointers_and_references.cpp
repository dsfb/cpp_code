#include <iostream>
#include <type_traits>

using std::is_same_v;
using std::cout;
using std::boolalpha;
#define nl '\n'

using type = int;
using const_type = const type;

using pointer_to_type = type*;
using pointer_to_const_type = const_type*;
using const_pointer_to_const_type = pointer_to_const_type const;

using reference_to_type = type&; // change original value
using reference_to_const_type = const_type&; // only see

// you can change an original pointer address and a variable value
using reference_to_pointer_to_type = pointer_to_type&;
// you can change an original pointer address
using reference_to_pointer_to_const_type = pointer_to_const_type &;
// unless you have a referecne you can't change either address not value
// this is useless one
using reference_to_const_pointer_to_const_type = const_pointer_to_const_type &;

void test_rtptt()
{
    type variable = 100;
    pointer_to_type ptt = &variable;
    //int v = 2;
    auto use_rtptt = [](reference_to_pointer_to_type rtptt)
    {
        *rtptt = 200;
    };

    use_rtptt(ptt);
    cout << *ptt << '\n';
}
int main()
{
    void test_rtptt();

    cout << boolalpha;
    cout << is_same_v<int, type> << nl;
    cout << is_same_v<const int, const_type> << nl;

    cout << is_same_v<int*, pointer_to_type> << nl;
    cout << is_same_v<const int*, pointer_to_const_type> << nl;
    cout << is_same_v<const int* const, const_pointer_to_const_type> << nl;

    cout << is_same_v<int&, reference_to_type> << nl;
    cout << is_same_v<const int&, const_reference_to_type> << nl;
    cout << is_same_v<int*&, reference_to_pointer_to_type> << nl;
    cout << is_same_v<int* const&, const_reference_to_pointer_to_type> << nl;
    cout << is_same_v<const int* const&, const_reference_to_pointer_to_const_type> << nl;
    return 0;
}
