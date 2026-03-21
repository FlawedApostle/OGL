#include <iostream>
#include <fstream>
#include <string>
#include "ReadFile.h"

//std::string line;
//std::string filepath;
//std::ifstream inputfile;

std::string ReadFile::ReadFile(std::string filename)
{
	std::string line;
	std::string filepath = filename;
	std::ifstream inputFile(filename);
	
	if (!inputFile.is_open()) {
		std::cout << "Error: Unable to open file: " << filepath << std::endl;
	}
	
	while (std::getline(inputFile, line))
	{
		std::cout << "Read line: " << line << std::endl;
	}

			inputFile.close();



			std::string fullContent; 
			return fullContent += line + "\n";
}
