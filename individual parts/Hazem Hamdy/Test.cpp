#include"tree.h"
#include"Helpers.h"
#include"Json.h"
#include"Graph.h"
#include<iostream>

using namespace std;

int main()
{
	vector <string> xml_vector = file_to_vector("graphsample.xml");
	Tree* XML_Tree = new Tree();
	XML_Tree->bulid_xml_tree(xml_vector);

	Graph* graph = new Graph();
	
	graph->create_useres_vector(XML_Tree->getRoot());
	//graph->print_vector();
	
	//_print_json(XML_Tree->getRoot(), true);
	//XML_Tree->print_xml();

	//string json = convert_to_json(XML_Tree->getRoot());
	//cout << json;
	cout << "///////////////////////// most_influencer user //////////////////////////////" << "\n";
	User most_influencer = graph->most_influencer_user();
	cout << "most influencer user name is: " << most_influencer.name << "\n";
	cout << "most influencer user id is: " << most_influencer.id << "\n";

	/*vector <User*> s = graph->get_users_vector();
	vector <string> postsOfTopic = s[0]->posts["economy"];*/
	/*vector <string> postsOfTopic = graph->post_search("sports");
	for (int i = 0; i < postsOfTopic.size(); i++)
	{
		cout << postsOfTopic[i] << "\n";
	}*/
	
	cout << "///////////////////////// most active user //////////////////////////////" << "\n";
	User most_active = graph->most_active_user();
	cout << "most active user name is: " << most_active.name << "\n";
	cout << "most active user id is: " << most_active.id << "\n";
	
	cout << "///////////////////////// mutual_followers between 1 and 4 //////////////////////////////" << "\n";
	vector <User> mutual_followers = graph->mutual_followers("1", "4");
	for (int i = 0; i < mutual_followers.size(); i++)
	{
		cout << mutual_followers[i].name << " of id: " << mutual_followers[i].id<<"\n";
	}
	cout << "///////////////////////// sugested followers for 2 //////////////////////////////" << "\n";
	vector <User> suggested_followers = graph->follow_suggestion("2");
	for (int i = 0; i < suggested_followers.size(); i++)
	{
		cout << suggested_followers[i].name << " of id: " << suggested_followers[i].id<<"\n";
	}
}