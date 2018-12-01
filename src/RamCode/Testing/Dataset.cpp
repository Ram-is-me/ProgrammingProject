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

void DataSet::add_a_column(vector<double> values)
{
    for(int i=0;i<data.size();i++)
    {
        vector<string> insertion;
        insertion = data[i].get_record();
        insertion.push_back(to_string(values[i]));
        Record *r = new Record(insertion);
        data[i] = *r;
    }
}

void DataSet::add_an_int_column(vector<int> values)
{
    for(int i=0;i<data.size();i++)
    {
        vector<string> insertion;
        insertion = data[i].get_record();
        insertion.push_back(to_string(values[i]));
        Record *r = new Record(insertion);
        data[i] = *r;
    }
}