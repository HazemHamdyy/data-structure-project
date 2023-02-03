#include"Compression.h"


// Converting 8 char (zero's & one's) to one ascii char 
char ed5at(string s)
{
	bits2char myChar;
	myChar.bits.bit7 = (int)(s[0] - '0');    // Set the LSB
	myChar.bits.bit6 = (int)(s[1] - '0');
	myChar.bits.bit5 = (int)(s[2] - '0');
	myChar.bits.bit4 = (int)(s[3] - '0');
	myChar.bits.bit3 = (int)(s[4] - '0');
	myChar.bits.bit2 = (int)(s[5] - '0');
	myChar.bits.bit1 = (int)(s[6] - '0');
	myChar.bits.bit0 = (int)(s[7] - '0');
    //if ((int)myChar.c < 0) {
        //myChar.c = (char)((int)myChar.c + 256);
    //}
    return myChar.c;
}


// Function to allocate a new tree node
HuffmanNode* getNode(char ch, int freq, HuffmanNode* left, HuffmanNode* right)
{
    HuffmanNode* node = new HuffmanNode();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}


// Build Nodes of Huffman Tree 
void compress(priority_queue<HuffmanNode*, vector<HuffmanNode*>, comp>& pq)
{
	if (pq.size() == 1) return;

    HuffmanNode* left = pq.top();
	pq.pop();
    HuffmanNode* right = pq.top();
	pq.pop();
	int sum = right->freq + left->freq;
	pq.push(getNode('\0', sum, left, right));
	//cout<< pq.top()->ch << pq.top()->freq ;
	compress(pq);
}

// To Bulid Huffman Tree & Retrurn Root
HuffmanNode* buildHuffmanTree(unordered_map<char, int> freq)
{

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, comp> pq;

	for (auto pair : freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	compress(pq);

	return pq.top();

}


// To Give Char Unique bits 
void encode(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr) return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


string  compressStringByHuffman(string text) 
{
	string compressedFile;
	string s;
	unordered_map<char, int> freq;

	for (char ch : text) {
		freq[ch]++;
	}

    HuffmanNode* root = buildHuffmanTree(freq);

	unordered_map<char, string> huffmanCode;

	encode(root, "", huffmanCode);

	
	for (char ch : text) {

		s += huffmanCode[ch];
		
	}

	int c = s.size() % 8;

	compressedFile = to_string(c);
	for (auto x : freq)
	{
		compressedFile = compressedFile + x.first + to_string(x.second) + ',' ;
	}
	compressedFile = compressedFile + "}0";
	int k = 0;
	while (k < s.size()-c)
	{
		//cout << ed5at(s.substr(k, k + 8));
		compressedFile.push_back (ed5at(s.substr(k, k + 8))) ;
		k = k + 8;
	}

	if (c != 0)
	{
		for (int i = c; i < 8; i++)
		{
			s = s + '0';
		}
		//cout << ed5at(s.substr(k, k + 8));
		compressedFile.push_back(ed5at(s.substr(k, k + 8)));
	}
	
	return compressedFile;
}
