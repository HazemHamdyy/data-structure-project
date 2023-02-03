#include"Graph.h"
#include<stack>
#include <algorithm>
#include <iostream>
using namespace std;

void Graph:: buid_graph(Node* node, stack <Node*> &nstack, User* user, bool idFlag, stack <string> &pstack)
{
	if (node != nullptr)
	{
		nstack.push(node);
		Node* temp = nstack.top();
		nstack.pop();
		if (temp->name == "user")
		{
			idFlag = true;
			User* user1 = new User;
			user = user1;
			users_vector.push_back(user);
		}
		else if(temp->name == "id")
		{
			if (idFlag)
			{
				user->id = temp->value;
				userlocation[user->id] = usersnum;
				usersnum++;
			}
			else
			{
				user->followers.push_back(temp->value);
			}
				
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
			posts[temp->value].push_back(pstack.top());
		}
		for (int i = 0; i < temp->children.size(); i++)
		{
			buid_graph(temp->children[i], nstack, user, idFlag, pstack);
		}
	}
}

void Graph::create_useres_vector(Node* node)
{
	stack <Node*> nstack;
	stack <string> pstack;
	User* user = new User;
	
	buid_graph(node, nstack, user, true, pstack);
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
	User max = *users_vector[0];
	for (int i = 1; i < users_vector.size();i++)
	{
		if (users_vector[i]->followers.size() > max.followers.size())
		{
			max = *users_vector[i];
		}
	}
	return max;
}

vector <string> Graph::post_search(string topic)   
{
	return posts[topic];
}

User Graph::get_user(string id)
{
	return *users_vector[userlocation[id]];
}

User Graph::most_active_user()
{
	vector<int> activity(users_vector.size(), 0);
	for (int i = 0; i < users_vector.size(); i++)
	{
		for (int j = 0; j < users_vector[i]->followers.size();j++)
		{
			int loc = userlocation[users_vector[i]->followers[j]];
			activity[loc]++;
		}
	}
	int max = activity[0];
	int max_loc = 0;
	for (int i = 1; i < activity.size(); i++)
	{
		if (activity[i] > max)
		{
			max = activity[i];
			max_loc = i;
		}
	}
	return *users_vector[max_loc];
}

//when use check if the returned vector is empty the there is mutual followers
vector<User> Graph::mutual_followers(string id1, string id2)
{
	User user1 = get_user(id1);
	User user2 = get_user(id2);
	vector <string> mutual;
	vector<User> mutual_followers;

	for (int i = 0; i < user1.followers.size(); i++)
	{
		for (int j = 0; j < user2.followers.size(); j++)
		{
			if (user1.followers[i] == user2.followers[j])
			{
				mutual.push_back(user1.followers[i]);
			}
		}
	}
	for (int i = 0; i < mutual.size(); i++)
	{
		mutual_followers.push_back(get_user(mutual[i]));
	}
	return mutual_followers;
}

vector<User> Graph::follow_suggestion(string id)
{
	vector<string> followers;
	vector<string> suggestions;
	vector<User> suggested_followers;
	User u = get_user(id);
	User temp;
	for (int i = 0; i < u.followers.size(); i++)
	{
		temp = get_user(u.followers[i]);
		for (int j = 0; j < temp.followers.size(); j++)
		{
			if (u.id != temp.followers[j])
				followers.push_back(temp.followers[j]);
		}
	}

	sort(followers.begin(), followers.end());
	followers.erase(unique(followers.begin(), followers.end()), followers.end());
	
	for (int i = 0; i < followers.size(); i++)
	{
		suggested_followers.push_back(get_user(followers[i]));
	}
	return suggested_followers;
}

