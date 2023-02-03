#include"removeSpaceAndUnique.h"

string removeSpacingAndUnique(string path) {

    bool v = true;
    string s;
    stack<string> c;
    int m;
    string k;
    vector <string> xmlData;
    vector <string> b;
    string field;
    fstream data;
    b.push_back("<>");
    data.open(path, ios::in | ios::out);
    if (data.fail()) {
        cerr << "Error Opening File!" << endl;
        exit(1);
    }

    while (getline(data, field)) {
        xmlData.push_back(field);
    }
    field.erase();
    for (int i = 0; i < xmlData.size(); i++)
    {
        m = 0;
        while (xmlData.at(i)[m] == ' ')m++;
        for (int j = m; j < xmlData.at(i).size(); j++)
        {
            if (xmlData.at(i)[j] == '<')
            {
                j++;
                if (xmlData.at(i)[j] == '/')
                {
                    j++;
                    while (xmlData.at(i)[j] != '>') { s = s + xmlData.at(i)[j]; j++; }
                    j++;

                    if (k == s)v = true;

                    if ((c.top() == s))
                    {
                        c.pop();
                        k = s;
                    }
                }
                else
                {
                    while (xmlData.at(i)[j] != '>')
                    {
                        s = s + xmlData.at(i)[j];
                        j++;
                    }
                    if (!c.empty())
                        if (s == k)v = false;

                    if ((s != b.back() && k != s && v == true))
                    {
                        b.push_back(s);
                        c.push(s);
                    }
                    j++;

                }
                s.erase();
            }

        }
    }
    data.close();
    b.erase(b.begin());
    for (unsigned i = 0; i < b.size(); i++)
    {
        field = field + b.at(i);
        field.push_back('.');
    }
    field.push_back('.');
    int p = 0;
    for (int i = 0; i < xmlData.size(); i++)
    {
        m = 0;
        while (xmlData.at(i)[m] == ' ')m++;
        for (int j = m; j < xmlData.at(i).size(); j++)
        {
            if (xmlData.at(i)[j] == '<')
            {
                field.push_back('<');
                j++;
                if (xmlData.at(i)[j] == '/') {
                    field.push_back('/');
                    j++;
                }

                while (xmlData.at(i)[j] != '>') { s = s + xmlData.at(i)[j]; j++; }
                j++;
                while (p < b.size())
                {
                    if (s == b.at(p))
                    {
                        field = field + to_string(p);
                        field.push_back('>');
                        break;
                    }
                    else { p = (static_cast<unsigned long long>(p) + 1) % b.size(); }
                }
            }
            field.push_back(xmlData.at(i)[j]);
            s.erase();
        }
    }
    return field;
}