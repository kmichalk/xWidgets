
#include "stdafx.h"

void display(void) {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);  /* blue */
	glRecti(100, 10, 200,300);

	//glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 1.0);  /* blue */
	//glVertex2f(0.9, 0.4);
	//glColor3f(0.0, 1.0, 0.0);  /* green */
	//glVertex2f(0.5, 0.5);
	//glColor3f(1.0, 0.0, 0.0);  /* red */
	//glVertex2f(-0.3, 0.2);
	//glColor3f(0.0, 0.7, 0.8);  /* blue */
	//glVertex2f(-0.8, -0.3);
	//glColor3f(0.5, 1.0, 0.0);  /* green */
	//glVertex2f(-0.5, -0.9);
	//glColor3f(1.0, 0.2, 1.0);  /* red */
	//glVertex2f(0.9, -0.9);
	//glEnd();
	//glFlush();
}


int mai9n(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	int x, y;

	glfwGetWindowPos(window, &x,&y);

	std::cout << x << " " << y << "\n";

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(1.0f, -1.0f, 1.0f);
	glViewport(0, 0, 640, 480);
	glOrtho(0, 640, 0, 480, -1, 1);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);
		display();
		/* Swap front and back buffers */
		//glfwSwapBuffers(window);
		glfwSwapBuffers(window);  /* Single buffered, so needs a flush. */	

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}