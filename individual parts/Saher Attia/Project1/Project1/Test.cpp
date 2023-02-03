#include"Consistency.h"
#include"Formatting.h"

int main()
{

    vector <err_data> error_vector;
    vector <string> corrected_vector;
    vector <string> xml_vector = file_to_vector("errorsample.xml");
    if (check_consistency(xml_vector))
    {
        cout << "no error in consistency" << "\n";
    }
    else
    {
        error_vector = detect_error(xml_vector);
        for (int i = 0; i < error_vector.size();i++)
        {
            cout << error_vector[i].err_type << " at location " << error_vector[i].err_loc << "\n";
        }
        corrected_vector = error_corrector(xml_vector, error_vector);
        if (check_consistency(corrected_vector))
        {
            cout << "file corrected successfully" << "\n";
            format(corrected_vector);
        }
    }

}