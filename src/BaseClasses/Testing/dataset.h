#ifndef DATASET_H
#define DATASET_H
#include <vector>
#include <string>
#include "record.h"
using namespace std;
class DataSet
{
    public:
    void read_from_csv(const string filename, int in);
    void output_to_csv(const string filename);
    void add_a_column(vector<double> values);
    void add_a_column_header(string heading);
    void add_an_int_column(vector<int> values);
    long no_of_records()
    {
        return data.size();
    } //Reading Data Set from CSV File
    vector<Record> get_data_set()
    {
        return data;
    }
    vector<Record> get_data_set() const
    {
        return data;
    }

    int get_n()
    {
        return n;
    }
    int get_n() const
    {
        return n;
    }

    Record get_record(int i)
    {
        return data[i];
    }

    void push_record(vector<string> str)
    {
        data.push_back(Record(str));
    }

    void set_record(vector<string> str, int i)
    {
        data[i] = Record(str);
    }

    void set_record(Record r, int i)
    {
        data[i] = r;
    }
    
    private:
    vector<Record> data;  //Data Set Representation
    int n;  //Number of Non-Numeric Columns
    vector<string> columnHeadings;  //Heading of each Column
};

#endif