#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>
#include <bitset>
#include <stack>
using namespace std;

// A Tree node
struct HuffmanNode      //struct huffnode
{
	char ch;
	int freq;
    HuffmanNode* left, * right;
};

// Data type which convert 8 bits to char
union bits2char
{
	struct {
		unsigned bit0 : 1;
		unsigned bit1 : 1;
		unsigned bit2 : 1;
		unsigned bit3 : 1;
		unsigned bit4 : 1;
		unsigned bit5 : 1;
		unsigned bit6 : 1;
		unsigned bit7 : 1;
	} bits;

	unsigned char c;
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(HuffmanNode* l, HuffmanNode* r)
	{
		// highest priority item has lowest frequency
		if (l->freq == r->freq) return (l->ch > r->ch);
		return (l->freq > r->freq);
	}
};


HuffmanNode* getNode(char ch, int freq, HuffmanNode* left, HuffmanNode* right);
void compress(priority_queue<HuffmanNode*, vector<HuffmanNode*>, comp>& pq);
HuffmanNode* buildHuffmanTree(unordered_map<char, int> freq);
void encode(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode);
string compressStringByHuffman(string text);

#endif // COMPRESSION_H
