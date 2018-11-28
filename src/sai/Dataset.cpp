#include "dataset.h"
#include <fstream>
#include <string>
#include <sstream>
#include "csvrow.h"

void DataSet::read_from_csv(const string filename, int n)
{
    ifstream file(filename);
    CSVRow row;

    while(file >> row)
    {
        // continue;
        // cout << "4th Element(" << row[3] << ")\n";
        Record *r;
        r = new Record(n, row.get_vector());
        data.push_back(*r);
    }

}