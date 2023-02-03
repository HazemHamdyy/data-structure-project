#include"Json.h"
#include <iostream>
#include <sstream>
void print_spaces(int numOfSpaces)
{
    for (int i = 0; i < numOfSpaces; i++)
    {
        cout << "  ";
    }
}

void _print_json(Node* node, bool print)
{
    static int numOfSpaces = 0;
    if (print)
    {
        print_spaces(numOfSpaces);
        cout << "\"" << node->name << "\": ";
    }
    if (node->children.empty())
    {
        if (!print)
        {
            print_spaces(numOfSpaces);
        }
        cout << "\"" << node->value << "\"," <<"\n";
    }
    else if (node->children.size() > 1 && node->children[0]->name == node->children[1]->name)
    {
        cout << "[" << "\n";
        numOfSpaces++;
        for (int i = 0; i < node->children.size(); i++)
        {
            if (node->children[i] != nullptr)
                _print_json(node->children[i], false);
        }
        numOfSpaces--;
        print_spaces(numOfSpaces);
        cout << "]" << "\n";
    }
    else
    {
        if (!print)
        {
            print_spaces(numOfSpaces);
        }
        cout << "{" << "\n";
        numOfSpaces++;
        for (int i = 0; i < node->children.size(); i++)
        {
            if (node->children[i] != nullptr)
                _print_json(node->children[i], true);
        }
        numOfSpaces--;
        print_spaces(numOfSpaces);
        cout << "}" << "\n";
    }
}

string convert_to_json(Node* node)
{
    std::stringstream ss;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    cout << "{" << "\n";
    _print_json(node, true);
    cout << "}" << "\n";

    std::cout.rdbuf(coutbuf);
    return ss.str();
}