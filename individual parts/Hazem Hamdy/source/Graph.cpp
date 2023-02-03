#include"Graph.h"
#include<stack>
#include <iostream>
using namespace std;

void Graph:: buid_graph(Node* node, stack <Node*> &nstack, User* user, bool idFlag, stack <string> &pstack)
{
	if (node != nullptr)
	{
		nstack.push(node);
		Node* temp = nstack.top();
		nstack.pop();
		if (temp->name == "users")
		{
			
		}
		else if (temp->name == "user")
		{
			idFlag = true;
			User* user1 = new User;
			user = user1;
			users_vector.push_back(user);

		}
		else if(temp->name == "id")
		{
			if (idFlag)
				user->id = temp->value;
			else
				user->followers.push_back(temp->value);

		}
		else if(temp->name == "name")
		{
			user->name = temp->value;
		}
		else if (temp->name == "body")
		{
			if (!pstack.empty())
			{
				pstack.pop();
			}
			pstack.push(temp->value);
		}
		else if (temp->name == "follower")
		{
			idFlag = false;
		}
		else if (temp->name == "topic")
		{
			user->posts[temp->value].push_back(pstack.top());
		}
		for (int i = 0; i < temp->children.size(); i++)
		{
			buid_graph(temp->children[i], nstack, user, idFlag, pstack);
		}
	}
	
}
vector <User*> Graph::get_users_vector()
{
	return users_vector;
}

void Graph::print_vector()
{
	for (int i = 0; i < users_vector.size(); i++)
	{
		cout << users_vector[i]->id <<"\n" << users_vector[i]->name << "\n";
		for (int j = 0; j < users_vector[i]->followers.size(); j++)
		{
			cout << users_vector[i]->followers[j]<<"\n";
		}
		cout << "////////////////////////////////////////////////////////"<<"\n";
	}
}

User Graph::most_influencer_user()
{
	User* max = users_vector[0];
	for (int i = 1; i < users_vector.size();i++)
	{
		if (users_vector[i]->followers.size() > max->followers.size())
		{
			max = users_vector[i];
		}
	}
	return *max;
}

vector <string> Graph::post_search(string topic)
{
	vector <string> posts;
	vector <string> temp;
	for (int i = 0; i < users_vector.size(); i++)
	{
		temp = users_vector[i]->posts[topic];
		if (!temp.empty())
		{
			for (int j = 0; j < temp.size(); j++)
			{
				posts.push_back(temp[j]);
			}
		}
	}
	return posts;
}

