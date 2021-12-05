#include "Window.h"

Window::Window(const char* title, int width, int height)
{
	assert(glfwInit() == GLFW_TRUE && "glfw initialization failed") ;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	hWnd = glfwGetWin32Window(window);
	glfwSetKeyCallback(window, Input::KeyCallback);
	glfwSetCursorPosCallback(window, Input::MousePosCallback);
	glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
	glfwSetScrollCallback(window, Input::MouseScrollCallback);
}

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::WindowShouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::PollEvent()
{
	glfwPollEvents();
}

HWND& Window::GetNativeWindow()
{
	return hWnd;
}

GLFWwindow* Window::GetGLFWWindow()
{
	return window;
}

void Window::StickyKey(bool isOn)
{
	if(isOn)
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
	else 
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
}
