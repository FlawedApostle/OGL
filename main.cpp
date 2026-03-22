
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "SDL3_image/SDL_image.h"       // image SDL
#include "SOIL/SOIL.h"                  // image openGL
#include "glm/vec3.hpp"                 // math
#include "TOL/tiny_obj_loader.h"        // fbx loader - tinyOBJ - header only
#include "ASSIMP/config.h"              // fbx - assimp static lib
#include "ASSIMP/revision.h"            // fbx - assimp static lib
#include <iostream>
#include <stdio.h>

#include "Window.h"
#include "Initialize.h"
#include "Timer.h"
#include "ReadFile.h"
#include "TestFunctions.h"
#include "ErrorChecking.h"

#define numVAOs 1                       //  preprocessor macro to re-write text to a number - Anytime numVAO is written its really a number = 1
GLuint renderingProgram;                //  ID for storing rending program - To use for running in RENDER/WHILE-LOOP
GLuint vao[numVAOs];                    //  VERTEX ARRAY OBJECTS - WRAPPER FOR VERTEX BUFFER OBJECTS - ENCAPSULAING HOW THE VBO's ARE INTERPRETED (POSITIONS,NORMALS,TEXTURE COORDS)

// Shader Calls
TestFunctions Shader_2;

int main(void)
{
    // 1. ------------------ LOAD GLFW _ SET OPENGL VER. CONTEXT
    std::cout << Timer::GetDateTime() << std::endl;
    Initialize::initGLFW();
    Initialize::SetWindowContext();
    
    // 2. ------------------ CREATE WINDOW OBJECT FOR RENDERRING
    Window Window_Main(640, 640, "Window Main");

    // 3. ------------------ LOAD GLAD _ GATHER OPENGL VER. CONTEXT/DRIVER INFO
    if (!Window_Main.GetWindow()) return false;
    Initialize::initGLAD();
    Initialize::GetDriveInfo();


    // 4. ------------------ BUFFERS
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);

    // 5. ------------------ RENDERS
    renderingProgram = Shader_2.Render2();                                      // NOTE:: NO LONGER STATIC - TESTFUNCTIONS IS NOW A CLASS 
    glPointSize(10.0f);

    /* Loop until the user closes the window */
    while (!Window_Main.WindowShouldClose())
    {
        double time = glfwGetTime();
        
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);                                           // CLEAR SCREEN BUFFER
        glUseProgram(renderingProgram);                                         // RUN THE PROGRAM
        
        glDrawArrays(GL_POINTS, 0, 1);                                          // DRAW THE PROGRAM
        
        ErrorChecking::checkOpenGLError();                                      // DEBUGGING - OPENGL ERROR HANDLE

        // ---------------- TEST FUNCTIONS
        //TestFunctions::Render1(time);


        /* Swap front and back buffers */
        glfwSwapBuffers(Window_Main.GetWindow());
        glfwPollEvents();
        //_window.Update();                                                     // SWAP BUFFERS MOVED TO WINDOW UPDATE

        /* Poll for and process events */
        glfwPollEvents();                                                       // DONE IN WINDOWS
    }




    return 0;                                                    //Initialize::Destroy(_window.GetWindow());     // Window Destructor DOes this now
}