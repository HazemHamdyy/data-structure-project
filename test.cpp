#include<iostream>
#include <string>
#include <fstream>
#include <vector>
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



/////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////




int main()
{

    vector <string> xml_vector = file_to_vector("sample.xml");

    for (int i = 0; i < xml_vector.size(); i++)
    {
        cout << xml_vector[i] << "\n";
    }


}