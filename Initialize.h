#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class Initialize {

protected:
    static bool initGLFW_Internal();
    static bool initGLAD_Internal();

    static bool SetWindowContext_Internal();
    static bool GetDriveInfo_Internal();


    [[noreturn]] static void CleanUp_Internal(GLFWwindow* window);
public:

    static bool initGLFW();
    static bool initGLAD();

    static bool SetWindowContext();
    static bool GetDriveInfo();


    [[noreturn]] static void Destroy(GLFWwindow* window);


};


