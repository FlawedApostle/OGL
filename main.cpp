
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "SDL3_image/SDL_image.h"       // image SDL
#include "SOIL/SOIL.h"                  // image openGL
#include "glm/vec3.hpp"                 // math
#include "TOL/tiny_obj_loader.h"        // fbx loader - tinyOBJ - header only
#include "ASSIMP/config.h"              // fbx - assimp static lib
#include "ASSIMP/revision.h"            // fbx - assimp static lib

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "Window.h"
#include "Initialize.h"
#include "Timer.h"
#include "ReadFile.h"
#include "TestFunctions.h"
#include "ErrorChecking.h"
#include "ReadShader.h"
#include "KeyCallbacks.h"

#define numVAOs 1                       //  preprocessor macro to re-write text to a number - Anytime numVAO is written its really a number = 1
GLuint renderingProgram;                //  ID for storing rending program - To use for running in RENDER/WHILE-LOOP
GLuint vao[numVAOs];                    //  VERTEX ARRAY OBJECTS - WRAPPER FOR VERTEX BUFFER OBJECTS - ENCAPSULAING HOW THE VBO's ARE INTERPRETED (POSITIONS,NORMALS,TEXTURE COORDS)

// Shader Calls
TestFunctions Shader_2;



int main(void)
{
    std::ifstream test("E:\\Documents\\GithubDir\\OGL\\Dep\\Shaders\\");

    if (test.is_open())
    {
        std::cout << "MINIMAL TEST: FILE OPENED\n";
    }
    else
    {
        std::cout << "MINIMAL TEST: FAILED\n";
    }

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

    // 5. ------------------ LOAD THE RENDERING PROGRAM ------------------
    renderingProgram = Shader_2.Render2();                                      // NOTE:: NO LONGER STATIC - TESTFUNCTIONS IS NOW A CLASS 
    glPointSize(10.0f);

    
    // ------------------ Read the shader file  -- ReadShaderFile.h
    std::string _filepath = "E:\\Documents\\GithubDir\\OGL\\Dep\\Shaders\\test.txt";
    std::string _shadersrc = ReadShader::ReadShaderSource(_filepath.c_str());               // CONVERT string to char to run through function - this is for debugging so I can check if the correct file is being read
    // DEBUG
    /*ReadShader::PrintShaderSourceFileName(_filepath);                       
    //std::cout << "FILE CONTENT:\n" << _shadersrc << std::endl;
    */

    // ----------------- KEY CALLBACKS  -- KeyCallbacks.h
    glfwSetKeyCallback(Window_Main.GetWindow(), KeyCallbacks::Key_callback_ESCAPE);

    /* Loop until the user closes the window */
    while (!Window_Main.WindowShouldClose())
    {
        double time = glfwGetTime();
        
        
        // ------ BUFFER - SCREEN CLEAR
        glClear(GL_COLOR_BUFFER_BIT);                                           // CLEAR SCREEN BUFFER
        
        // ------ RUN AND DRAW SHADER PROG                                      // lOADING SHADER IN ---- 5. LOAD THE RENDERING PROGRAM 'OnCreate'
        glUseProgram(renderingProgram);
        glDrawArrays(GL_POINTS, 0, 1);                                          // DRAW

        // ------ TEST FUNCTIONS
        //TestFunctions::Render1(time);

        /* 
        //if (glfwGetKey(Window_Main.GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        //{
        //    const int scancode = glfwGetKeyScancode(GLFW_KEY_ESCAPE);
        //    printf("Escape\nScancode: %d\n" , scancode);
        //    glfwSetWindowShouldClose(Window_Main.GetWindow(), GLFW_TRUE);
        //} 
        */


        glfwPollEvents();
       
        // ------ BUFFERS - WINDOW SCREEN
        glfwSwapBuffers(Window_Main.GetWindow());
    }




    return 0;                                                    //Initialize::Destroy(_window.GetWindow());     // Window Destructor DOes this now
}