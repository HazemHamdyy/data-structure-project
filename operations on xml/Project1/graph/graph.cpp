#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>

using namespace std;

class User {
    private:
       struct postNode {
    string body;
    string topic;
     };
       static int id;
        string name;
        vector<postNode*> posts;
        vector<User> followers;


    public : 
    User(string name){}


};


class Graph {
    private : 
    struct postNode {
    string body;
    string topic;
};

struct userNode {
    int id;
    string name;
    vector<postNode*> posts;
    vector<userNode*> followers;
};
vector<userNode*> adjList;

    public : 
    void createUser(){

    }
    void addUser(userNode* user){
        adjList.push_back(user);
    }
    
};