#ifndef GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include "Window.h"
#include "Graphics.h"

int main(int argv, char** args) {

	Window* window = new Window("title", 1366, 768);
	window->StickyKey(true);

	Graphics graphics(window);
	float color[4] = {
		0.3f, 0.5f, 0.8f, 1.0f
	};
	while (!window->WindowShouldClose()) {
		window->PollEvent();
		
		graphics.SwapBuffer();
		graphics.Clear(color);
	}
	
	delete window;
	return 0;
}