#ifndef CONSISTENCY_H
#define CONSISTENCY_H

#include"Helpers.h"

struct err_data
{
    string err_type;
    int err_loc;
};

bool consistency_checker(string opent, string closedt, stack <string>& s);
bool check_consistency(vector <string> xml_vector);

bool error_detector(string opent, string closedt, stack <string>& s, string& error_type);
vector <err_data> detect_error(vector <string> xml_vector);

vector <string> error_corrector(vector <string> xml_vector, vector <err_data> error_vector);

string printError (vector <err_data> error_vector);

#endif
