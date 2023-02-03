#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H
#include <bitset>
#include<vector>
using namespace std; 

struct HuffmanNode;
string convertStringToBinary(string compressedText);
void decode(string s, HuffmanNode* root, int& index,string & str);
vector<string> decompress(string compressedText);

#endif // DECOMPRESSION_H