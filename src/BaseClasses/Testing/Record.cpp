#include "record.h"

Record::Record(const vector<string> input)
{
    record = input;
}

Record::Record(const Record &other)
{
    record = other.get_record();
}
