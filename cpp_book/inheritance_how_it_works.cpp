/* show me how an inharitance works in C++ */

// kształt
class shape
{
public:
	// virtual keyword is mandatory for a polimorphic class
	// =0 means that a function must be defined in a child class
	virtual int get_area() = 0;
	// 1) if a destructor of a base class is virtial, a child destructor becomes virtual too
	// 2) virtual means: I want to use last available method - said a pointer.
	// 3) it is called "late binding"
	// 4)moreover, a destructor must have a body in order to delete the object
	// (child will call him after its destructor)
	virtual ~shape() {};
};

class rectangle : public shape
{
	// there is a hidden virtual destructor
public:
	// "virtual" keyword is optional for a child class
	virtual int get_area() override {
		return height * width;
	} 
protected:
	float width; // szerokość
	float height; // wysokość
};

// trójkąt
class triangle : public shape
{
	// there is a hidden virtual destructor
public: 
	int get_area() override {
		return (1.f/2.f) * side * height;
	}
private:
	float side; // strona
	float height; // wysokość
};

int main()
{
	rectangle* r = new rectangle();
	triangle* t = new triangle();
	shape* s = nullptr;
	s = t;
	s->get_area();
	delete s;
	s = t;
	delete s;
	return 0;
}
