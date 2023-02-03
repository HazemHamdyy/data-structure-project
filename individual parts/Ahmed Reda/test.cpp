#include"removeSpaceAndUnique.h"
#include"Compression.h"
#include"Decompression.h"
#include<fstream>
#include <sstream>
#include <string>
#include <iostream>


std::string readFileIntoString(const std::string& fileName) {
	std::ifstream file(fileName);
	if (!file) {
		std::cerr << "Error opening file: " << fileName << '\n';
		return "";
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string contents = buffer.str();

	file.close();

	return contents;
}





int main()
{
	string s = removeSpacingAndUnique("D:\\Dowanloads\\sample (1).xml");


	cout << s;
	cout << "------------------------------------------------------------------";
	 s = compressStringByHuffman(s);
	 cout << s;

	 cout << "######################################################################";
	fstream formatted_file;
	 formatted_file.open("formatted_file.txt", ios::out);
	 if (!formatted_file) {
		 cout << "Formatted file not created!";
	 }
	 else {
		 cout << "Formatted file created successfully!";
	 }

	 formatted_file << s;

	 
	 formatted_file.close();

	 cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	 std::string contents = readFileIntoString("formatted_file.txt");
	 std::cout << contents << '\n';
	cout << "######################################################################################################"<< endl;

	vector<string> originalData= decompress(contents);
	for (auto x : originalData) 
	{
		cout << x << endl;
	}
	 
}