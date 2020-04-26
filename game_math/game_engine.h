/*
there required libraries:
inst libglew-dev
inst libglfw3-dev
inst libglm-dev - C++ library for OpenGL GLSL type-based mathematics
*/

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using std::cout;
#define nl '\n';


// Include GLEW
//#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
//#include <glm/glm.hpp>
//using namespace glm;

#include <GL/gl.h>

bool initialize()
{
    // Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return;
	}

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 400, 400, "Tutorial 01", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	/*if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}*/

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


    glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );

	// set up view
	glViewport( 0, 0, 400, 400 );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
	glOrtho(0.0,400.0,0.0,400.0,0.0,1.0); // this creates a canvas you
	// Dark white background
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// set size of all points
	glPointSize(15);

	return true;
}


typedef void (*draw)();

void add_scene(draw scene)
{
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    do{

        // select the color of the brush
        glColor3f(0.0f, 0.0f, 0.0f);

		(*scene)();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

float inline convert_to_radians(float degrees)
{
    return (degrees * 3.1415f) / 180.0f;
}

void draw_point(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}


//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

namespace game_engine
{
    struct vector2d
    {
        float x1;
        float y1;
        float x2;
        float y2;

        float length() const
        {
            // to get the vector a (ax, ay)
            const float ax = x1 - x2;
            const float ay = y2 - y2;
            // to get the length = sqrt(ax^2 + ay^2)
            return sqrt(ax * ax + ay * ay);
        }
    };
}