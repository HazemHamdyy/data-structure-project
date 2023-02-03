#include "huffman_compress.h"

/*
this auxiliary function used by calculate_huffman_codes() function
traverse the huffman tree and get huffman code for a character
save the huffman code in code data member of node of every character
*/
void traverse(node_ptr node, string code)
{
	/*
	if you reach leaf node(node belong to character)(not internal node)
	put the huffman code to code member in this node (setting huffman code) 
	*/
	if (node->left == NULL && node->right == NULL)
	{
		node->code = code;
	}
	else
	{
		/*
							root
							/   \
						   /	 \
						 (0)	 (1)
						 /		   \
						/			\
				  left child		right child
		*/
		traverse(node->left, code + '0');
		traverse(node->right, code + '1');
	}
}

/*
convert a binary code(8 bits)(represented as string of 0 and 1 ) to a decimal integer
*/
int binary_to_decimal(string in) {
	/*
	For binary number with n digits:
	dn-1 ... d3 d2 d1 d0
	The decimal number is equal to the sum of binary digits (dn) times their power of 2 (2n):
	decimal = d0×2^0 + d1×2^1 + d2×2^2 + ...
	*/
	int result = 0;
	for (int i = 0; i < in.size(); i++) {
		/*
		we substract from '0' --> to convert digit from char( '1' ) to integer( 1 )
		'5'-'0' = 5
		*/
		result = result * 2 + (in[i] - '0');
	}
	return result;
}

//constructor t
/*
gets freq of each character in file and set the freq of character node to it
then add the nodes of character that exists in the file to priority queue
if any character of 128 character in the Ascii Table does not exists in the file
then its character nodes will not added to priority queue
*/
void huffman_compress::build_priority_queue()
{

	//varivable used to store character readed from file	
	char character_readed;
	/*
	Opening the original file
	we will read from it so we use " ios::in"
	*/
	in_file.open(in_file_name, ios::in);
	in_file.get(character_readed);
	/*
	looping in every char in file to count its freq
	set freq of every character in their nodes in node_array
	*/
	while (!in_file.eof())
	{

		node_array[character_readed]->freq++;
		in_file.get(character_readed);
	}
	/*
	now  freq of character node  is seted to the freq of character in file
	this is done for 128 character in the Ascii Table
	*/
	in_file.close();

	/*
	add the nodes of character that exists in the file to priority queue
	if any character of 182 character in the Ascii Table does not exists in the file
	then its character nodes will not added to priority queue
	*/
	for (int i = 0; i < 128; i++)
	{
		if (node_array[i]->freq) //its freq >0 then its exits in file at least one time
		{
			pq.push(node_array[i]);
		}
	}
}

/*
build the huffman tree ,making characters nodes as leafs
the most frequency character will be leaf node near to root (smallest depth) (small huffman code)
the least frequency character will be leaf node far from root (largest depth) (big huffman code)
*/
void huffman_compress::build_huffman_tree()
{
	/*
	copy priority queue that contain character nodes to temporary priority queue
	so we don't change or play with the original priority queue
	*/
	priority_queue<node_ptr, vector<node_ptr>, compare> temp(pq);

	/*
	exit from while loop when there is only just one element
	last node will be the root of the tree
	*/
	while (temp.size() > 1)
	{
		/*
		Extract two nodes with the minimum frequency from priority queue.
		Create a new internal node with a frequency equal to the sum of the two nodes frequencies.
		Make the first extracted node as its left child and the other extracted node as its right child.
		Add this node to the priority queue..
		-------------------------------------------
		Repeat steps until the priority queue contains only one node.
		The remaining node is the root node and the tree is complete.
		*/
		root = new huffman_node;
		root->freq = 0;
		root->left = temp.top(); //extract one of the 2 minimum frequency nodes and make it as left child of root
		root->freq += temp.top()->freq; //freq = freq of left node
		temp.pop(); //we will pop so we can use top() to get the second minimum freq node 

		root->right = temp.top(); //extract the other minimum frequency node and make it as right child of root
		root->freq += temp.top()->freq; //freq = freq of left node + freq of right node
		temp.pop(); //we will pop so the 2 minimum freq is poped from priority queue

					//adding the new node which its frequency is sum of last 2 minimum frequency nodes before deleting them from priority queue
		temp.push(root);
	}
}

/*
traverse the huffman tree and get huffman code for a character
save the huffman code in code data member of node of every character
*/
void huffman_compress::calculate_huffman_codes()
{
	traverse(root, "");
}

/*
creating the Encoded File (Compressed File) that will consist of 2 main parts
header: priority queue size - huffman codes for Every Character in file
data: compressed data(replacement of every character in file to its huffman code)
*/
void huffman_compress::compression_saving_to_compressed_file()
{

	in_file.open(in_file_name, ios::in);
	string in = "";
	string s = "";
	in += (char)pq.size();
	priority_queue<node_ptr, vector<node_ptr>, compare> temp(pq);
	while (!temp.empty())
	{
		node_ptr current = temp.top();
		in += current->id; 			  
		s.assign(127 - current->code.size(), '0');
		s += '1';
		s.append(current->code);
		in += (char)binary_to_decimal(s.substr(0, 8));
		for (int i = 0; i < 15; i++)
		{
			s = s.substr(8); 
			in += (char)binary_to_decimal(s.substr(0, 8));
		}
		temp.pop();
	}
	s.clear();
	char character_readed;
	in_file.get(character_readed);
	while (!in_file.eof())
	{
		s += node_array[character_readed]->code;
		{
			in += (char)binary_to_decimal(s.substr(0, 8));
			s = s.substr(8);	
		}
		in_file.get(character_readed); 
	}
	int count = 8 - s.size();
	if (s.size() < 8)
	{
		s.append(count, '0');
	}
	in += (char)binary_to_decimal(s);	
	in += (char)count;							
	out_file.open(out_file_name, ios::out | ios::binary);
	out_file.write(in.c_str(), in.size());
	in_file.close();
	out_file.close();
}

//user interface for all steps for comprssing operation
void huffman_compress::compress_file()
{
	this->build_priority_queue();
	this->build_huffman_tree();
	this->calculate_huffman_codes();
	this->compression_saving_to_compressed_file();
}