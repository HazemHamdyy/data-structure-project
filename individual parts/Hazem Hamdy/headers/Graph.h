#include"User.h"
#include"tree.h"
#include<unordered_map>
using namespace std;
class Graph 
{
private:

	vector<User*> users_vector;

public:
	void buid_graph(Node* node, stack <Node*>& nstack, User* user, bool idFlag, stack <string> &pstack);
	void print_vector();
	User most_influencer_user();
	vector <User*> get_users_vector();
	vector <string> post_search(string topic);
	
};
