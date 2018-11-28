#include <iostream>
#include "dataset.h"
#include "matrix.h"

ostream& operator<<(ostream& str, Record& data)
{
    string temp("");
    for(int i=0;i<data.get_record().size();i++)
    {
        temp+=data.get_record()[i]+" ";
    }
    str<<temp;
    return str;
}

int main()
{
    DataSet d;
    d.read_from_csv("input.csv", 1);
    cout<<d.no_of_records()<<endl;
    for(int i=0;i<d.no_of_records();i++)
    {
        cout<<d.get_data_set()[i]<<endl;;
    }

    Matrix m(d.no_of_records(), d.get_data_set()[0].get_record().size());
    m.convert_from_dataset(d);

    for(int i=0;i<m.get_row_size();i++)
    {
        for(int j=0;j<m.get_matrix()[i].size();j++)
        {
            cout<<m.get_matrix()[i][j]<<" ";
        }
        cout<<endl;
    }

    m.output_to_csv("output.csv");
    return 0; 
}

