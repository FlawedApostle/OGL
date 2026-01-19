#include "Initialize.h"


void Initialize::initGLFW() {
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");
        
        printf("GLFW initialized\n");
    }