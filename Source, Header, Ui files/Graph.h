#ifndef GRAPH_H
#define GRAPH_H

#include"User.h"
#include"tree.h"
#include<unordered_map>
using namespace std;
class Graph 
{
private:
	int usersnum = 0;
	vector<User*> users_vector;
	unordered_map<string, vector<string>> posts;
	unordered_map<string, int> userlocation;
	void buid_graph(Node* node, stack <Node*>& nstack, User* user, bool idFlag, stack <string>& pstack);

public:
	void create_useres_vector(Node* node);
	void print_vector();
	User most_influencer_user();
	vector <string> post_search(string topic);
	User most_active_user();
	vector<User> mutual_followers(string id1, string id2);
	vector<User> follow_suggestion(string id);
	User get_user(string id);
};


#endif
