#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
	std::ofstream ofFile;
	std::ifstream inFile;
	std::string path = "C:/Users/User/coding/Labs 1.2/Lab-2/Csv files";
	for (const auto & entry : fs::directory_iterator(path))
	{
		//std::cout << entry.path() << std::endl;
		inFile.open(entry.path(), std::ofstream::app);
		if (!inFile.is_open()) {
			std::cout << "Cannot open the file" << std::endl;
		}
		else {
			std::cout << "File opened" << std::endl;
			int quant = 0;
			inFile >> quant;
			std::string str;
			inFile.ignore();
			std::cout << quant << std::endl;
			
			while (!inFile.eof()) {
				str = "";
				getline(inFile, str);
				std::cout << str << std::endl;
			}
		}
		inFile.close();
	}
	
}