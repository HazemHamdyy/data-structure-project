#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

class User
{
public:
    
    string name;
    string id;
    vector<string> followers;
    unordered_map<string, vector<string>> posts;
};

#endif
