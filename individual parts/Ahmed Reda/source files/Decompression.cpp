#include"Decompression.h"
#include"Compression.h"

//take a string of ascii chars ,then return string of zero's & one's
string convertStringToBinary(string compressedText )
{
	string str;

	for (int i = 0; i < compressedText.size(); i++) 
	{
		bitset<8> bin_x((int)compressedText[i]);
		str = str + bin_x.to_string();
	}
	return str ;
}


//convert huffman code(zero's & one's) to original char cy ascii
void decode(string s, HuffmanNode* root, int& index, string &str)
{

	// found a leaf node
	if (!root->left && !root->right)
	{
		str = str + root->ch;
		return;
	}

	if (s[index] == '0')decode(s, root->left, ++index,str);
	else decode(s, root->right, ++index,str);

}



vector<string> decompress(string compressedText) 
{
	int padding = compressedText[0] - '0'; 
	int i = 1 ;
	string  str;
	unordered_map <char, int> umap;
	vector<string> xmlData;
	vector<string> uniqueNames;


	// to take each char and freq to build huffman tree
	while (compressedText[i + 1] != '0' || compressedText[i] != '}')    
	{
		str.push_back(compressedText[i]); i++;
		while (compressedText[i] != ',')
		{
			str.push_back(compressedText[i]);
			i++;
		}
		umap[str[0]] = stoi(str.substr(1)); 
		str.erase(); i++;
	}
	i=i+2;
	
	HuffmanNode* root = buildHuffmanTree(umap);
	compressedText = convertStringToBinary(compressedText.substr(i));


	for (int x = 0; x < padding; x++) compressedText.pop_back();   //order el padding 0:7

	int index = 0;
	while (compressedText.size() != index) decode(compressedText, root, index,str); //convert zero's & one's to original text & store it it str

	// equal zero & null  only to use it in another task
	index = 0; 
	compressedText.erase();


	// to store unique name and store them in uniqueNames
	while (str[index] != '.' || str[index + 1] != '.') 
	{
		if (str[index] == '.') 
		{
			uniqueNames.push_back(compressedText);
			 index++;
			compressedText.erase();
		}

		compressedText = compressedText + str[index] ;
		index++;
	}
	uniqueNames.push_back(compressedText);
	index =index + 2;

	// remove data from string compressedText to use in another task not need to declare a new string
	compressedText.erase();
	string temporaryBus;


	// store every  original text line in xmlData then send it to formatting
	while (index < str.size()) 
	{
		if (str[index] == '<') 
		{
			//     Doning this condition because between >< null char && first of string may null char    
			//										     /\
			//							           		 ||
			//											 ||
			if (temporaryBus.size() != 0 && (int)temporaryBus[temporaryBus.size()-1] != 0)
			{
				xmlData.push_back(temporaryBus);
				temporaryBus.erase();
			}
			temporaryBus = "<";
			index++;
			if (str[index] == '/')
			{
				temporaryBus += '/';
				index++;
			}
			while (str[index] != '>') { compressedText = compressedText + str[index]; index++; }
			index++;
			temporaryBus += uniqueNames[stoi(compressedText)] + '>';
			xmlData.push_back(temporaryBus);
			temporaryBus.erase();
			compressedText.erase();
		}
		temporaryBus += str[index]; index++; 
	}

	return xmlData;

}