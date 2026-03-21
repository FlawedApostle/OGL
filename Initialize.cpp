#include "glad/glad.h"
//#include <GLFW/glfw3.h>
#include <iostream>
#include "Initialize.h"

// ------------- SETTERS
bool Initialize::initGLFW_Internal()
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
        return false;
    }
    printf("GLFW initialized\n");
    return true;
}
bool Initialize::initGLAD_Internal()
{
    /// Glad Loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return false;
    }

    printf("GLAD Initialized\n");
    return true;
}
bool Initialize::SetWindowContext_Internal()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return false;
}

bool Initialize::GetDriveInfo_Internal()
{
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* vendor = glGetString(GL_VENDOR);

    std::cout << "GLFW VERSION: " << version << std::endl;
    std::cout << "GLFW RENDERER: " << renderer << std::endl;
    std::cout << "GLFW VENDOR: " << vendor << std::endl;
    return false;
}
[[noreturn]]void Initialize::CleanUp_Internal(GLFWwindow* window)
{
    if (window)
    {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
    printf("Destroyed Window\nExit Success\n");
    exit(EXIT_SUCCESS);
}


// ----------- GETTERS
bool Initialize::initGLFW() 
{
    return initGLFW_Internal();
}

bool Initialize::initGLAD() 
{
    return initGLAD_Internal();
}

bool Initialize::SetWindowContext()
{
    return SetWindowContext_Internal();
}

// Wont run untill Context is set
bool Initialize::GetDriveInfo()                         
{
    return GetDriveInfo_Internal();
}

// DO not return to the caller - just clean up and exit - always check for clean up message on console
[[noreturn]] void Initialize::Destroy(GLFWwindow* window)
{
    CleanUp_Internal(window);
}


// Old Deprecated function - older OpenGL ver.
//void Initialize::initGlew() {
//    /// have to call after glfwMake context
//    GLenum err = glewInit();
//    if (GLEW_OK != err) {
//        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
//    }
//    // Have to run after  glewInit() !
//    printf("Status: GLEW OK !\n");
//    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
//    std::cout << glGetString(GL_VERSION) << std::endl;
//}