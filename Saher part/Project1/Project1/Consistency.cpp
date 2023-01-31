#include"Consistency.h"

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

////////////////////////////////////////////////////////////////////////////////////////////////

bool error_detector(string opent, string closedt, stack <string>& s, string& error_type)
{
    stack <string> temp;

    if (opent.compare("FALSE") && closedt.compare("FALSE"))
    {
        if (opent.compare(closedt))
        {
            error_type = "not matching tags: " + opent + " and " + closedt;
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



vector <err_data> detect_error(vector <string> xml_vector)
{
    vector <err_data> error_vector;
    err_data error;
    string error_type;
    stack <string> s;
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
                if (error_type.size() > 25)           //for mismatching tags
                {
                    error.err_type = error_type;
                    error.err_loc = i;
                    error_vector.push_back(error);
                }
                else
                {
                    error.err_type = error_type;
                    error.err_loc = i;
                    error_vector.push_back(error);
                }
            }
        }
    }
    int i = xml_vector.size();
    while (!s.empty())
    {
        string err = "</" + s.top() + ">";
        error.err_type = err;
        error.err_loc = i;
        error_vector.push_back(error);
        i++;
        s.pop();
    }
    return error_vector;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

vector <string> error_corrector(vector <string> xml_vector, vector <err_data> error_vector)
{
    int counter = 0;
    vector <string> corrected_vector;
    for (int i = 0; i < xml_vector.size(); i++)
    {
        if (i == error_vector[counter].err_loc)
        {
            if (error_vector[counter].err_type.size() > 25)                //not matching tags error
            {
                string temp_s = replace_str(xml_vector[i], getClosedTag(xml_vector[i]), getOpenTag(xml_vector[i]));
                corrected_vector.push_back(temp_s);
            }
            else                          //normal error
            {
                corrected_vector.push_back(error_vector[counter].err_type);
                corrected_vector.push_back(xml_vector[i]);
            }
            if (counter < error_vector.size() - 1)
                counter++;
        }
        else
            corrected_vector.push_back(xml_vector[i]);
    }
    if (counter < error_vector.size() - 1)
    {
        for (int i = counter; i < error_vector.size(); i++)
        {
            corrected_vector.push_back(error_vector[i].err_type);
        }
    }
    return corrected_vector;
}