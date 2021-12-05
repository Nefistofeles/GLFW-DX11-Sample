#pragma once
#include <GLFW/glfw3.h>
#define MAX_KEY 350
#define MAX_MOUSE_KEY 12

enum class KeyType {
	None = 0,
	Pressed,
	Repeat,
	Released
};
class Input
{
	friend class Window;
private :
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MousePosCallback(GLFWwindow* window, double xpos, double ypos);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static KeyType keys[MAX_KEY];
	static KeyType mouseKeys[MAX_MOUSE_KEY];
	static float mousePosition[2];
	static float scrollPosition[2];
public :
	static bool GetKey(int key, KeyType keyType);
	//[0] = x, [1] = y
	static float* GetMousePosition();
	static float* GetScrollPosition();
	static bool GetMouseKey(int key, KeyType keyType);
};

