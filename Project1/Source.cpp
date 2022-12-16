#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

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
    if (start != -1 && t[start + 1] != '/')
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

bool consistency_checker(string opent, string closedt, stack <string>& s)
{
    if (opent.compare("FALSE"))
    {
        s.push(opent);
    }
    if (closedt.compare("FALSE"))
    {
        if (!s.empty())
        {
            if (!closedt.compare(s.top()))
                s.pop();
            else
            { 
                return false;
            }
        }
        else
        {
            return false;
        }
        return true;
    }      
}

bool check_consistency(vector <string> xml_vector)
{
    stack <string> s;
    int error = 0;
    string line;
    for (int i = 0; i < xml_vector.size(); i++)
    {
        line = xml_vector[i];
        string opent;
        string closedt;
        opent = getOpenTag(line);
        closedt = getClosedTag(line);

        if (opent.compare("FALSE") || closedt.compare("FALSE"))
        {
            if (!consistency_checker(opent, closedt, s))
            {
                return false;
            }
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////////
// formatting
/////////////////////////////////////////////////////////////////////////////

void format(vector <string> xml_vector)
{
    int numOfSpaces = 0;
    fstream formatted_file;
    formatted_file.open("formatted_file.xml", ios::out);
    if (!formatted_file) {
        cout << "Formatted file not created!";
    }
    else {
        cout << "Formatted file created successfully!";
    }

    string line;
    for (int i = 0; i < xml_vector.size(); i++)
    {
        line = xml_vector[i];
        string opent;
        string closedt;
        opent = getOpenTag(line);
        closedt = getClosedTag(line);

        if (closedt.compare("FALSE") && !opent.compare("FALSE"))
        {
            numOfSpaces--;
        }

        for (int i = 0; i < numOfSpaces; i++)
        {
            formatted_file << "    ";
        }
        formatted_file << line << "\n";

        if (closedt.compare("FALSE") && opent.compare("FALSE"))
        {
            numOfSpaces--;
        }

        if (opent.compare("FALSE"))
        {
            numOfSpaces++;
        }
    }
    formatted_file.close();
}
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main() {

    vector <string> xml_vector = file_to_vector("errorsample.txt");
    if (check_consistency(xml_vector))
    {
        cout << "no error in consistency" << "\n";
    }
    else
        cout << "there is an error in consistency" << "\n";

    format(xml_vector);
}
