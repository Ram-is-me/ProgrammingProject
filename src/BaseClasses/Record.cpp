#include "record.h"

Record::Record(const int in, const vector<string> input)
{
    record = input;
    n = in;
    for(int i=n-1;i<input.size();i++)
    {
        numRow.push_back(stod(input[i]));
    }
}

Record::Record(const Record &other)
{
    record = other.get_record();
    n = other.get_n();
    for(int i=n-1;i<other.get_record().size();i++)
    {
        numRow.push_back(stod(other.get_record()[i]));
    }
}