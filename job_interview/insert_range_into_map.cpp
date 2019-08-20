#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        //if(keyEnd > numeric_limits<K>::max())
            //return;

         // 1) map entries must not have the same value:
         for (const auto& map_pair : m_map) {
              if (map_pair.second == val) {
                   cout << "the value exists " << map_pair.second << "/" << val << endl;
                   return;
              }
         };


         auto i = keyBegin;
         while (i <= keyEnd)
         {
             m_map.insert_or_assign(i, val);
             ++i;
        } 
    } 

    void print()
    {
        cout << "***" << endl;
        for (const auto& map_pair : m_map) {
                   cout << map_pair.first << '/' << map_pair.second << endl;
         }
    }

// look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

int main()
{
     cout << "it runs" << endl;
     interval_map<unsigned, char> m('a');
     m.print();
     m.assign(1, 10, 'b');
     m.print();
     
     m.assign(6, 10, 'c');
     m.print();
     return 0;
}