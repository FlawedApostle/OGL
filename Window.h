#pragma once
#include <iostream>


class Window {
protected:
    GLFWwindow* win;
public:
    GLFWwindow* Get_Window() { return win; }
    GLFWwindow* Set_Window(GLFWwindow* window) { return win = window; }

    GLFWwindow* testWin;

	GLFWwindow* InitWindow(GLFWwindow** win);                   // create the window using the initialized var the user provides
	void DisplayWindow(GLFWwindow* window, double time);        // Display the window with time - color, and clear

};
