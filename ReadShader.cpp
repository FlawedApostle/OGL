#include "ReadShader.h"
#include <iostream>
#include <fstream>
#include <sstream>



std::string ReadShader::ReadShaderSource(const char* filePath)
{
    std::cout << "PATH RECEIVED: [" << filePath << "]\n";
    std::cout << "LENGTH: " << strlen(filePath) << "\n";

    std::ifstream fileStream(filePath);

    // DEBUG
    std::cout << "GOOD: " << fileStream.good() << "\n";
    std::cout << "FAIL: " << fileStream.fail() << "\n";
    std::cout << "BAD: " << fileStream.bad() << "\n";
    std::cout << "IS_OPEN: " << fileStream.is_open() << "\n";

    if (!fileStream.is_open())
    {
        std::cerr << "ERROR: Could not open shader file: " << filePath << std::endl;
        return "";
    }


    std::stringstream buffer;
    buffer << fileStream.rdbuf();


    return buffer.str();
}

void ReadShader::PrintShaderSourceFileName(std::string fileName)
{
    // Print each character manually
    for (size_t i = 0; i < fileName.size(); i++)
    {
        std::cout << fileName[i] << " (" << (int)fileName[i] << ")\n";
    }


}
