#ifndef TREE_H
#define TREE_H
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    std::string name;
    string value;
    std::vector<Node*> children;
};

class Tree
{
private:
    Node* Root;

    void _print_xml(Node* node);

public:
    void bulid_xml_tree(vector <string> xml_vector);
    void print_xml();
    Node* getRoot();
};

#endif