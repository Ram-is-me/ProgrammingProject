#include "dataset.h"
#include "csvrow.h"
#include <fstream>
#include <string>
#include <sstream>


void DataSet::read_from_csv(const string filename, int in)
{
    ifstream file(filename);
    CSVRow row;
    n = in;
    while(file >> row)
    {
        // continue;
        // cout << "4th Element(" << row[3] << ")\n";
        Record *r;
        r = new Record(row.get_vector());
        data.push_back(*r);
    }

    file.close();
}

void DataSet::output_to_csv(const string filename)
{
    ofstream file(filename);
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[i].get_record().size();j++)
        {
            file<<data[i].get_record()[j]<<";";
        }
        file<<endl;
    }
    file.close();
}