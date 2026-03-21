#pragma once
#include <iostream>
#include <string>
// clean this up and make the functions private - so setters & getters

class Window {
protected:
    GLFWwindow* win = nullptr;
public:


    Window(int width, int height, const char* title);
    
    ~Window()
    {
        printf("Window Destructor\n");
        if (win) 
        {  
            glfwDestroyWindow(win);
            printf("Destroyed win\n");
        }
    }

    GLFWwindow* const GetWindow() { return win;  };                                 // --------- GETTER
    bool const WindowShouldClose() { return glfwWindowShouldClose(win); }           // check Windows Flags

    // - RENDERING LOOP UESED IN MAIN
    void Update();

    // ----------- DEBUGGER 
    /* pointer to a pointer
    // - when user creates *window this function takes the raw value dereferences it to update it
    // - create the window using the initialized var the user provides */
	static GLFWwindow* InitWindow(GLFWwindow** win);                                

};
