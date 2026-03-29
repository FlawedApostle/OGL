#include "KeyCallbacks.h"

void KeyCallbacks::Key_callback_ESCAPE(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
{
	if (_key == GLFW_KEY_ESCAPE && _action == GLFW_PRESS)
	{
		printf("Escape\nScancode Key: %d\n", _scancode);
		glfwSetWindowShouldClose(_window, GLFW_TRUE);
	}
}
