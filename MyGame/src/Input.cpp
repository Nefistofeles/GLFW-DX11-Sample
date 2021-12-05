#include "Input.h"

KeyType Input::keys[MAX_KEY];
float Input::mousePosition[2];
KeyType Input::mouseKeys[MAX_MOUSE_KEY];
float Input::scrollPosition[2];

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key >= MAX_KEY) {
		return;
	}
	switch (action) {
	case GLFW_PRESS :
		keys[key] = KeyType::Pressed;
		break;
	/*case GLFW_REPEAT:
		keys[key] = KeyType::Repeat;
		break;*/
	case GLFW_RELEASE:
		keys[key] = KeyType::Released;
		break;
	}
}

void Input::MousePosCallback(GLFWwindow* window, double xpos, double ypos)
{
	mousePosition[0] = (float)xpos;
	mousePosition[1] = (float)ypos;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button >= MAX_MOUSE_KEY) {
		return;
	}
	switch (action) {
	case GLFW_PRESS :
		mouseKeys[button] = KeyType::Pressed;
		break;
	case GLFW_RELEASE:
		mouseKeys[button] = KeyType::Released;
		break;
	}

}

void Input::MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	scrollPosition[0] += (float)xoffset;
	scrollPosition[1] += (float)yoffset;
}

bool Input::GetKey(int key, KeyType keyType)
{
	if (key >= MAX_KEY)
		return false;

	if (keys[key] == keyType) {
		if (keyType == KeyType::Released)
			keys[key] = KeyType::None;
		return true;
	}
	return false;
}

float* Input::GetScrollPosition()
{
	return scrollPosition;
}

bool Input::GetMouseKey(int key, KeyType keyType)
{
	if (key >= MAX_MOUSE_KEY)
		return false;

	if (mouseKeys[key] == keyType) {
		if (keyType == KeyType::Released)
			mouseKeys[key] = KeyType::None;
		return true;
	}
	return false;
}

float* Input::GetMousePosition()
{
	return mousePosition;
}
