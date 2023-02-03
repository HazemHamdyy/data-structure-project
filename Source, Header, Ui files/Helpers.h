#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

static inline void ltrim(string& s);
static inline void rtrim(string& s);
static inline void trim(string& s);
string replace_str(string str, const string& toReplace, const string& replaceWith);

vector <string> file_to_vector(string file_loc);
string getOpenTag(string t);
string getClosedTag(string t);
string getTagValue(string t);


#endif
