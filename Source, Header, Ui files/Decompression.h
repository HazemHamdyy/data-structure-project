#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include <bitset>
#include "Compression.h"

using namespace std; 

string convertStringToBinary(string compressedText);
string readFileIntoString(const std::string& fileName);
void decode(string s, HuffmanNode* root, int& index,string & str);
vector<string> decompress(string compressedText);

#endif // DECOMPRESSION_H
