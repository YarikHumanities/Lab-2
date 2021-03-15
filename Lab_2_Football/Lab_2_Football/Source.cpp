#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main() {
	std::ofstream ofFile;
	std::ifstream inFile;
	std::string path;
	std::cout << "Entry path: " << std::endl;
	std::getline(std::cin, path);
	std::string path2 = "raiting.csv";
	for (const auto& entry : fs::directory_iterator(path))
	{
		//std::cout << entry.path() << std::endl;
		if (entry.path().extension() == ".csv") {
			inFile.open(entry.path());
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
			else
			{
				std::cout << "File opened" << std::endl;
				int quant;
				inFile >> quant;
				std::string str;
				inFile.ignore();
				//std::cout << quant << std::endl;

				while (!inFile.eof())
				{
					str = "";
					getline(inFile, str);
					if (str.size() > 0)
					{
						//std::cout << str;
						std::string name = std::string(str, 0, str.find(','));
						ofFile << name << ",";
						int pos = str.find(',');
						int score = 0;

						int start = pos, end = pos;

						while (end < str.size())
						{
							start = end;
							while (start < str.size() && str[start] == ',')
							{
								++start;
							}
							end = start;
							while (end < str.size() && str[end] != ',')
							{
								++end;
							}
							std::string part = std::string(str, start, end - start);
							std::string first;
							std::string second;
							std::string A = std::string(part, 0, part.find(':'));
							std::string B = std::string(part, part.find(':') + 1, part.size() - part.find(':'));
							first = A;
							second = B;
							char valueA = A[0];
							if (valueA >= 'A' && valueA <= 'F') {
								int k;
								switch (valueA) {
									case 'A': k = 10; break;
									case 'B': k = 11; break;
									case 'C': k = 12; break;
									case 'D': k = 13; break;
									case 'E': k = 14; break;
									case 'F': k = 15; break;
								}
								int scoreSecond = std::atoi(B.c_str());
								if (k > scoreSecond) {
									score += 3;
								}
								else if (k == scoreSecond) {
									score += 1;
								}
							}
							else {


								int scoreFirst = std::atoi(A.c_str());
								int scoreSecond = std::atoi(B.c_str());

								std::cout << scoreFirst << " " << scoreSecond << std::endl;
								if (scoreFirst > scoreSecond) {
									score += 3;
								}
								else if (scoreFirst == scoreSecond) {
									score += 1;
								}
							}
						}
						ofFile << score << std::endl;
					}
				}
			}
		}
		/*else
		{
			std::cout << "Not CSV" << std::endl;
		}*/
		inFile.close();
		ofFile.close();
	}

}