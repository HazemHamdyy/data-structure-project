#include"Formatting.h"

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