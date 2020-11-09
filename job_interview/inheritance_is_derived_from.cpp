/*
1. Implement a template function IsDerivedFrom() that takes class C and class P as template parameters.
It should return true when class C is derived from class P and false otherwise.
*/

/*
my solution:
g++ -std=c++17 inheritance_is_derived_from.cpp -o main && ./main
1) a class is polimorphic when it has one or more virtual method
2) you cannot create an object of an abstract class
3) an abstract class means you have some pure virtual method
4) your destructor of base class must have a body to remove of an object fully
5) you must have a virtual destructor if you remove an obeject by using
 a pointer to base class. a pointer to base class does not know about
  destructor of child-part. 
 */

#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;
using std::boolalpha;

class abstract{
	protected:
	virtual void empty() = 0;
};

class parent { 
	public:
	/* virtual*/ ~parent() { cout << "~parent()" << endl; }
	virtual void method() {}
};

class child : public parent, public abstract {
	virtual void empty() override {};
};

template <class C, class P>
bool isDerivedFrom()
{
	C* c = new C();
	bool isDerived =  dynamic_cast<P*> (c) != nullptr;
	
	// it will remove good, becouse pointer type equals to value type
	// otherwise you must add a virtual destructor for base class
	delete c;
	return isDerived;
}

int main()
{
	cout << boolalpha;
	cout << "it is abstract = ";
	cout << std::is_abstract<abstract>::value << endl; // true

	cout << "parent derived from child = ";
	cout << isDerivedFrom<parent, child>() << endl; // false

	cout << "child derived from parent = ";
	cout << isDerivedFrom<child, parent>() << endl; // true

	cout << "parent is base of child = ";
	cout << std::is_base_of<parent, child>::value << endl; // true
}