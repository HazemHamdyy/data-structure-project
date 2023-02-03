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
//error detection
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////




int error_location(int curr_loc, string error_type, vector <string> xml_vector)
{
    if (error_type[0] == '<' && error_type[1] != '/')         //missing open tag case
    {
        stack <string> s;
        string line;
        for (int i = curr_loc; i >= 0; i--)
        {
            line = xml_vector[i];
            string opent;
            string closedt;
            closedt = getOpenTag(line);
            opent = getClosedTag(line);

            if (opent.compare("FALSE") || closedt.compare("FALSE"))
            {
                if (!consistency_checker(opent, closedt, s))
                {
                    return i + 1;
                }
            }
        }
    }


}

bool error_detector(string opent, string closedt, stack <string>& s , string &error_type)
{
    stack <string> temp;

    if (opent.compare("FALSE") && closedt.compare("FALSE"))
    {
        if (opent.compare(closedt))
        {
            error_type = "not matching tags: "  + opent + " and " + closedt;
            return false;
        }
    }

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
            else                            //there is an error
            {
                while (!s.empty() && closedt.compare(s.top()))    //top not equal closed tag and stack is not empty
                {
                    temp.push(s.top());
                    s.pop();
                }
                if (s.empty())     //mean that it is a missed open tag = closedt
                {
                    error_type = "<" + closedt + ">";
                    while (!temp.empty())    
                    {
                        s.push(temp.top());
                        temp.pop();
                    }
                }
                else              //mean that it is a missed closed tag = top of the stack
                {
                    s.pop();
                    while (!temp.empty())
                    {
                        s.push(temp.top());
                        temp.pop();
                    }
                    error_type = "</" + s.top() + ">";
                    s.pop();
                }
                return false;
            }
        }
        else
        {
            error_type = "<" + closedt + ">";
            return false; //error at location zero
        }
        return true;
    }
}





void detect_error(vector <string> xml_vector)
{
    string error_type;
    stack <string> s;
    int error = 0;
    string line;
    int err_loc = -1;
    for (int i = 0; i < xml_vector.size(); i++)
    {
        line = xml_vector[i];
        string opent;
        string closedt;
        opent = getOpenTag(line);
        closedt = getClosedTag(line);

        if (opent.compare("FALSE") || closedt.compare("FALSE"))
        {
            if (!error_detector(opent, closedt, s, error_type))
            {
                if (error_type.size() > 25)
                    cout << error_type<<"\n";
                else
                    cout <<"missing "<< error_type << "\n";
            }
        }
    }
    while (!s.empty())
    {
        string err = "</" + s.top() + ">";
        cout <<"missing "<< err<<"\n";
        s.pop();
    }
}









int main() {

    
    vector <string> xml_vector = file_to_vector("errorsample.txt");
    if (check_consistency(xml_vector))
    {
        cout << "no error in consistency" << "\n";
    }
    else
    {
        detect_error(xml_vector);
    }
        

}
