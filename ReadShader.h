#pragma once
#include <iostream>
#include <string>
class ReadShader
{
protected:

public:

	static std::string ReadShaderSource(const char* filePath);
	static void PrintShaderSourceFileName(std::string fileName);

};

