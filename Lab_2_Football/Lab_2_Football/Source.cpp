#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
	std::ofstream ofFile;
	std::string path = "C:/Users/User/coding/Labs 1.2/Lab-2/Csv files";
	for (const auto & entry : fs::directory_iterator(path))
	{
		//std::cout << entry.path() << std::endl;
		ofFile.open(entry.path(), std::ofstream::app);
		if (!ofFile.is_open()) {
			std::cout << "Cannot open the file" << std::endl;
		}
		else {
			std::cout << "File opened" << std::endl;
		}
		ofFile.close();
	}
	
}