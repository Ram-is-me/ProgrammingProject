#ifndef DATASET_H
#define DATASET_H
#include <vector>
#include <string>
#include "record.h"
using namespace std;
class DataSet
{
    public:
    DataSet();
    DataSet(const long size);
    void read_from_csv(const string filename);
    long no_of_records()
    {
        return data.size();
    } //Reading Data Set from CSV File
    private:
    vector<Record> data;  //Data Set Representation
};

#endif