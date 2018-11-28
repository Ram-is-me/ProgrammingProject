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
    
    private:
    vector<Record> data;  //Data Set Representation
    int n;  //Number of Non-Numeric Columns
};

#endif