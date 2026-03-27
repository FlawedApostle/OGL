#include "ReadShader.h"
#include <iostream>
#include <fstream>


std::string ReadShader::ReadShaderSource(const char* filePath)
{
    std::string content;
    std::ifstream fileStream;
    std::string line = "";

    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");

        std::cout << line << "\n" << std::endl;
    }

    fileStream.close();
    return content;
}
