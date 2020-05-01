#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

void resizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(void)
{
	float x = 0;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(640, 360, "Hello, World", NULL, NULL);
	if (!window) 
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD!";
		return -1;
	}

	glViewport(0, 0, 640, 360);
	glfwSetFramebufferSizeCallback(window, resizeCallback);

	while (!glfwWindowShouldClose(window))
	{
		x += 0.0001f;
		processInput(window);

		glClearColor(fmod(x, 1), fmod((2 * x), 1), fmod((1.5f * x), 1), 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void resizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}