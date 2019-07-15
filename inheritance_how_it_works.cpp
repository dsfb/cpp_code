/* show me how does an inharitance works in C++ */

// kształt
class shape
{
public:
	// virtual is mandatory for a polimorphic class
	virtual int get_area() = 0;
	// virtual means: I want to use last available method - said the pointer.
	// it calls "late binding"
	// moreover, the destructor must have a body in order to delete the object
	// (child will call him after itself)
	virtual ~shape() {};
};

class rectangle : public shape
{
public:
	// virtual is optional for child' class
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