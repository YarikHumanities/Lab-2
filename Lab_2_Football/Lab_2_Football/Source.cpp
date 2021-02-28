#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
	std::ofstream ofFile;
	std::ifstream inFile;
	std::string path = "C:/Users/User/coding/Labs 1.2/Lab-2/Csv files";
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
				ofFile<<name<<",";
				int pos = str.find(',');
				int score = 0;
				
				//for (int i = pos + 1; i < str.size(); i++)
				//{
					int start = 0, end = 0;

					while (end < str.size()) {
						start = end;
						while (start < str.size() && str[start] == ',') {
							start++;
						}
						end = start;
						while (end < str.size() && str[end] != ',') {
							end++;
						}
						std::string part = std::string(str, start, end - start);
						//std::cout << part << std::endl;
						//part.find(':');
		
						std::string first;
						std::string second;
						std::string A = std::string(part, 0, part.find(':'));
						std::string B = std::string(part, part.find(':')+1, part.size() - part.find(':'));
						first = A;
						second = B;
						int scoreFirst = std::stoi(A);
						int scoreSecond = std::stoi(B);
						std::cout << scoreFirst<<" "<<scoreSecond<< std::endl;

					}
					/*if (str[i] >str[i + 2]) 
					{
						score += 3;
					}
					else if (str[i] == str[i + 2])
					{
						score += 1;
					}*/
				//}
				ofFile << score << "\n";
				//std::cout << str << std::endl;	
			}
		}
		inFile.close();
		ofFile.close();
	}
	
}