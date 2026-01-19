#pragma once
#include <iostream>


class Window {
protected:
    GLFWwindow* win;
public:
    GLFWwindow* Get_Window() { return win; }
    GLFWwindow* Set_Window(GLFWwindow* window) { return win = window; }

    GLFWwindow* testWin;

    GLFWwindow* DeployWindow(GLFWwindow** win);

};
