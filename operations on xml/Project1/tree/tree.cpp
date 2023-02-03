#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <stack>

using namespace std;

string globalContent  = "<users><user><id>1</id><name>Ahmed Ali</name><posts><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>economy</topic><topic>finance</topic></topics></post><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>solar_energy</topic></topics></post></posts><followers><follower><id>2</id></follower><follower><id>3</id></follower></followers></user><user><id>2</id><name>Yasser Ahmed</name><posts><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>education</topic></topics></post></posts><followers><follower><id>1</id></follower></followers></user><user><id>3</id><name>Mohamed Sherif</name><posts><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>sports</topic></topics></post></posts><followers><follower><id>1</id></follower></followers></user></users>";

class Node {
    public : 
    string name;
    string value;
    vector<Node*> children;

    Node(const string& name,const string& value="") : name(name) ,value(value){};
};

class XmlTree {
    private:
    std::stack<Node*> stack;
   
    public :
     Node* roott;
     XmlTree(string content) {
          std::stack<Node*> stack;
         Node root(globalContent);
      stack.push(&root);

  for (int i = 0; i < content.size(); ++i) {
    switch (content[i]) {
      case '<': {
        std::string tag;
        while (content[++i] != '>') {
          tag += content[i];
        }
        if (tag[0] == '/') {
          stack.pop();
        } else {
          Node node(tag);
          stack.top()->children.push_back(&node);
          stack.push((stack.top()->children.back()));
        }
        break;
      }
      case ' ':
      case '\n':
      case '\r':
      case '\t':
        break;
      default: {
        std::string val;
        while (content[i] != '<') {
          val += content[i++];
        }
        stack.top()->value=val;
        break;
      }
    }
  }
      roott = &root;
  //return root;

    }

    void display(Node* root){
     cout<<root->name;
    if(root->value != "NULL"){
        cout<<root->value;}
    
        for(int i = 0 ; i<root->children.size();i++){
            display(root->children[i]);
        }
    

    }

};

int main() {
  XmlTree tree =  XmlTree(globalContent);
  tree.display(tree.roott);
  return 0;
}

// #include <stack>
// #include <map>
// #include <vector>
// #include <string>

// class Node {
//  public:
//   std::string name;
//   std::map<std::string, std::string> attributes;
//   std::vector<Node> children;

//   Node(const std::string& name) : name(name) {}
// };

// int main() {
//   std::stack<Node*> stack;
//   Node root("root");
//   stack.push(&root);

//   for (int i = 0; i < content.size(); ++i) {
//     switch (content[i]) {
//       case '<': {
//         std::string tag;
//         while (content[++i] != '>') {
//           tag += content[i];
//         }
//         if (tag[0] == '/') {
//           stack.pop();
//         } else {
//           Node node(tag);
//           stack.top()->children.push_back(node);
//           stack.push(&stack.top()->children.back());
//         }
//         break;
//       }
//       case ' ':
//       case '\n':
//       case '\r':
//       case '\t':
//         break;
//       default: {
//         std::string value;
//         while (content[i] != '<') {
//           value += content[i++];
//         }
//         stack.top()->children.push_back(Node(value));
//         break;
//       }
//     }
//   }

//   // do something with the root node
// }