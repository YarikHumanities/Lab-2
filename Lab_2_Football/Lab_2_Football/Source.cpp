#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
	std::ofstream ofFile;
	std::ifstream inFile;
	std::string path = "G:/lab rep/Lab-2/Csv files";
	std::string path2 = "raiting.csv";
	for (const auto& entry : fs::directory_iterator(path))
	{
		//std::cout << entry.path() << std::endl;
		inFile.open(entry.path(), std::ofstream::app);
		ofFile.open(path2, std::ofstream::app);
		if (!ofFile.is_open()) {
			std::cout << "Cannot open the second file" << std::endl;
		}
		else {
			std::cout << "second file is opened\n";
		}
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
				//std::cout << str;
				std::string name= std::string(str,0, str.find(','));
				ofFile<<name<<";";
				int pos = str.find(',');
				int score = 0;
				for (int i = pos + 1; i < str.size(); i += 4)
				{
					if (str[i] >str[i + 2]) 
					{
						score += 3;
					}
					else if (str[i] == str[i + 2])
					{
						score += 1;
					}
				}
				ofFile << score << "\n";
				std::cout << str << std::endl;	
			}
		}
		inFile.close();
		ofFile.close();
	}
	
}