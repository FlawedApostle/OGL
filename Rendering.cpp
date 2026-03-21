
#include <glad/glad.h>
#include "Rendering.h"

bool Rendering::Program_Clear(GLuint prog)
{
    if (prog)
    {
        glDeleteProgram(prog);
        printf("Program Exists\n");
    }
    else

        printf("No Program Exists\n");
    
    
    return false;
}
