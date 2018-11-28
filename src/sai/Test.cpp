#include <iostream>
#include "dataset.h"

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
    return 0; 
}

