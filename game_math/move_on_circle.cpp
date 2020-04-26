 /*
the task:
create function in order to move an object on a circle trajectory

the command to compile and run below code:
g++ -Wall -o main move_on_circle.cpp -lGL -lGLEW -lglfw && clear && ./main &

there are required libraries:
inst libglew-dev
inst libglfw3-dev
inst libglm-dev 
inst libgl-dev

my solution:
https://www.mathsisfun.com/geometry/unit-circle.html
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