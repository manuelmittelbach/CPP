#include <iostream>
#include <string>
#include <fstream> 

int main(int argc, char**argv)
{
	if (argc != 4) {
	std::cerr << "number of arguments must be 3\n";
	return (1);
	}

	if (std::string(argv[2]).empty()) {
	std::cerr << "s1 must not be empty\n";
	return (1);
	}

	// open the input file
	std::ifstream file;
	file.open(argv[1]);
	if (!file.is_open()) {
    std::cerr << "could not open file\n";
	return (1);
	}

	// read the whole file content
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();


	// replace every occurrence of s1 with s2
	std::string result;
	size_t pos = 0;
	size_t found = content.find(argv[2], pos);
	while (found != std::string::npos) {
	result += content.substr(pos, found - pos);
	result += argv[3];
	pos = found + std::string(argv[2]).length();
	found = content.find(argv[2], pos);
	}
	result += content.substr(pos);

	// write the result into the new file
	std::string newFilename = std::string(argv[1]) + ".replace";
	std::ofstream outFile(newFilename.c_str());
	if (!outFile.is_open()) {
    std::cerr << "could not create output file\n";
    return 1;
	}
	outFile << result;
	outFile.close();
	
	return (0);
}