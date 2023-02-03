#include"Helpers.h"

static inline void ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
        }));
}

// trim from end (in place)
static inline void rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string& s) {
    ltrim(s);
    rtrim(s);
}


string replace_str(string str, const string& toReplace, const string& replaceWith) {
    size_t pos = str.find(toReplace);

    while (pos != string::npos) {
        str.replace(pos, toReplace.length(), replaceWith);
        pos = str.find(toReplace, pos + replaceWith.length());
    }

    return str;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

vector <string> file_to_vector(string file_loc)
{
    vector<string> xml_file;

    ifstream oldfile;
    oldfile.open(file_loc, ios::in); //open a file to perform read operation using file object
    if (oldfile.is_open()) {   //checking whether the file is open
        string tp;
        while (getline(oldfile, tp)) {

            trim(tp);
            xml_file.push_back(tp);

        }
        oldfile.close();
        return xml_file;
    }
    else
    {
        cout << " Failed to open" << endl;
    }

}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

string getOpenTag(string t)
{
    int start = -1;
    int end = -1;
    start = t.find("<", 0);
    end = t.find(">", start);
    if (start != -1 && t[start + 1] != '/' && t[start + 1] != '?' && t[start + 1] != '!')
        return t.substr(start + 1, end - start - 1);
    else
        return "FALSE";
}

string getClosedTag(string t)
{
    int start = -1;
    int end = -1;
    start = t.find("/", 0);
    end = t.find(">", start);
    if (start != -1)
        return t.substr(start + 1, end - start - 1);
    else
        return "FALSE";
}