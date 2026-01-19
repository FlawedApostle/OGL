#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Initialize.h"


bool Initialize::initGLFW() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
        return false;
    }
        printf("GLFW initialized\n");
        return true;
}

bool Initialize::initGLAD() {
    /// Glad Loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    
    {
        std::cerr << "Failed to initialize GLAD\n";
        return false;
    }
    
    printf("GLAD Initialized\n");
    std::cout << glGetString(GL_VERSION) << std::endl;
    return true;
}


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