#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
/// <KEY CALLBACKS FUNCTIONS>
/// https://www.glfw.org/docs/3.3/input_guide.html#input_keyboard
/// Functions are SET-INSIDE 'OnCreate' In main BEFORE the while loop.
/// **** MUST MATCH THIS EXACT SIGNATURE: **** (GLFWwindow*, int, int, int, int) 
/// </summary>

class KeyCallbacks
{
public:
	static void Key_callback_ESCAPE(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);

};

