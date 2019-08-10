#include <iostream>
#include <type_traits>

using std::is_same_v;
using std::cout;
using std::boolalpha;
#define nl '\n';

using type = int;
using const_type = const type;

using pointer_to_type = type*;
using pointer_to_const_type = const_type*;
using const_pointer_to_const_type = pointer_to_const_type const;

using reference_to_type = type&;
using const_reference_to_type = const_type&;

using reference_to_pointer_to_type = pointer_to_type&;
using const_reference_to_pointer_to_type = pointer_to_type const&;
using const_reference_to_pointer_to_const_type = pointer_to_const_type const&;

void test_rtptt()
{
    int var = 100;
    pointer_to_type ptt = &var;
    int v = 2;
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