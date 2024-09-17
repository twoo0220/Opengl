﻿#include "Inflearn_OpenGL.h"

int main()
{
	if (!glfwInit())
	{
		std::cerr << "glfwInit Error\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "twoo0220", NULL, NULL);
	if (window == nullptr)
	{
		glfwTerminate();
		std::cerr << "glfwCreatWindow failed\n";
		return -1;
	}

	glfwMakeContextCurrent(window);
	//glfwSetKeyCallback(window, );

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "GLEW init failed\n";
	}

	int width(640), height(480);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		//glUseProgram(shaderProgram);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}
