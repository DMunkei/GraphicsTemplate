#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW init failed\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(1280, 720, "My App Title", nullptr, nullptr);
	if (!window)
	{
		std::cerr << "Window creation failed\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize OpenGL context\n";
		return -1;
	}

	int profileBit;
	glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &profileBit);

	std::cout << "OpenGL Version " << GLVersion.major << "." << GLVersion.minor << " "
			  << (profileBit == 1 ? "Core" : "Compatibility") << '\n';

	glfwSetKeyCallback(window,
		[](GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			// Keyboard Input
			std::cout << key << '\n';
			
			if (key == GLFW_KEY_ESCAPE)
			{
				exit(0);
			}
		});
	glfwSetMouseButtonCallback(window,
		[](GLFWwindow *window, int button, int action, int mods)
		{
			// Mouse Input
		});
	glfwSetScrollCallback(window,
		[](GLFWwindow *window, double xoffset, double yoffset)
		{
			// Scroll Wheel Input
		});
	glfwSetCursorPosCallback(window,
		[](GLFWwindow *window, double xpos, double ypos)
		{
			// Mouse Motion Input
		});

	// Init here

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw here
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
