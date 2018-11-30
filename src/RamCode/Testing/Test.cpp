#include <iostream>
#include "dataset.h"
#include "matrix.h"
#include "task1.h"
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
    srand(time(NULL));

    DataSet d;
    int n=1;
    d.read_from_csv("input.csv", n);
    cout<<d.no_of_records()<<endl;

    d.output_to_csv("dataoutput.csv");

    Matrix m(d.no_of_records(), d.get_data_set()[0].get_record().size());
    // m.re_size(d.no_of_records(), d.get_data_set()[0].get_record().size());
    m.convert_from_dataset(d);

    for(int i=0;i<m.get_row_size();i++)
    {
        for(int j=0;j<m.get_matrix()[i].size();j++)
        {
            cout<<m.get_matrix()[i][j]<<" ";
        }
        cout<<endl;
    }

    int k;
    cin>>k;
    runTask1("input.csv","outputcs.csv", "outputkclusterid.csv", n, k);

    m.output_to_csv("outputm.csv");
    return 0; 
}

