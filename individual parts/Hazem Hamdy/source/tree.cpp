#include"tree.h"
#include"Helpers.h"


Node* Tree::getRoot()
{
    return Root;
}

void Tree::bulid_xml_tree(vector <string> xml_vector)
{
    int loc = 0;
    stack<Node*> stack;
    Node* root = new Node;
    while (getOpenTag(xml_vector[loc]) == "FALSE")
    {
        loc++;
    }
    root->name = getOpenTag(xml_vector[loc]);
    root->value = "";
    stack.push(root);

    for (int i = loc+1; i < xml_vector.size(); i++)
    {
        string closedt = getClosedTag(xml_vector[i]);
        string opent = getOpenTag(xml_vector[i]);

        if (closedt == "FALSE" && opent == "FALSE")
        {
            stack.top()->value = xml_vector[i];
        }
        else if (closedt != "FALSE" && opent != "FALSE")
        {
            Node* node1 = new Node;
            node1->name = opent;
            node1->value = getTagValue(xml_vector[i]);
            stack.top()->children.push_back(node1);
        }
        else if (closedt == "FALSE" && opent != "FALSE")
        {
            Node* node1 = new Node;
            node1->name = opent;
            stack.top()->children.push_back(node1);
            stack.push(stack.top()->children.back());
        }
        else if (closedt != "FALSE" && opent == "FALSE")
        {
            stack.pop();
        }
    }
    this->Root = root;
}


void Tree::_print_xml(Node* node)
{
    cout << "<" << node->name << ">" << "\n";
    if (!node->value.empty())
    {
        cout << node->value << "\n";
    }
    for (int i = 0; i < node->children.size(); i++)
    {
        if (node->children[i] != nullptr)
            _print_xml(node->children[i]);
    }
    cout << "</" << node->name << ">" << "\n";
}

void Tree::print_xml()
{
    _print_xml(Root);
}
