#pragma once

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "Input.h"

class Window
{
	friend class Input;
private :
	HWND hWnd;
	GLFWwindow* window;
public :
	Window(const char* title, int width, int height);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	bool WindowShouldClose();
	void PollEvent();

	HWND& GetNativeWindow();
	GLFWwindow* GetGLFWWindow();
	void StickyKey(bool isOn);

};

