#include "dataset.h"

DataSet::DataSet()
{
    data.resize(10000);
}

DataSet::DataSet(const long size)
{
    data.resize(size);
}

void DataSet::read_from_csv(const string filename)
{
    
}