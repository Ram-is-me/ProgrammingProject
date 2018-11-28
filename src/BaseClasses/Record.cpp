#include "record.h"

Record::Record(const int in, const vector<string> input)
{
    record = input;
    n = in;
}

Record::Record(const Record &other)
{
    record = other.get_record();
    n = other.get_n();
}