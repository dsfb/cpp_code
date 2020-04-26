 /*
the task:
implement function update() in order to move an object on a circle trajectory

my solution:
at the beginning I plan to read about the circle and I read this
https://www.mathsisfun.com/pythagoras.html
https://www.mathsisfun.com/sine-cosine-tangent.html
https://www.mathsisfun.com/geometry/unit-circle.html


x
^	    . p (px, py)
|       /|
|      / |
|    c/  |b
|    /   |
|   /    |
|  /     |
| /      |
|/sin____|
|    a    
-------------->y

1) p (px, py) - this is the point on the circle that we want to know to build full circle
2) there is triangle with sides a, b and c as you can see
3) there is the angle sin that has coordinates (0, 0)


a^2 + b^2 = c^2
c = 1 = radius
c^2 = 1

then 

sin = b / c = b / radius => b = sin * c
cos = a / c = a / radius => a = cos * c

while

b = px
a = py

other words

p(px, py) = p(a, b)
the end of math part

the command to compile and run below code:
g++ -Wall -o main move_on_circle.cpp -lGL -lGLEW -lglfw && clear && ./main &

there are required libraries:
inst libglew-dev
inst libglfw3-dev
inst libglm-dev 
inst libgl-dev

*/
#include "game_engine.h"

const float circle_radius = 200.f;
const float max_radians = 2 * 3.14;
const float velocity = 0.1f;
const float offset = 200.f;


void set_position(float x, float y)
{
	draw_point(x, y);
}

void update() 
{
	static float angle = 0.f;

	if (angle <= max_radians)
	{
		float rx = circle_radius * sin(angle) + offset;
		float ry = circle_radius * cos(angle) + offset;
		set_position(rx, ry);
		angle = angle + velocity;
	}
	else
	{
		angle = 0.f;
	}
}

int main()
{
	const bool is_alive = initialize();
	if (is_alive) add_scene(update);
	return 0;
}