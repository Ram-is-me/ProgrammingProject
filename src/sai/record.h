#ifndef RECORD_H
#define RECORD_H
#include <vector>
#include <string>
using namespace std;
class Record
{
    public:
    Record(const int in, const vector<string> input); //Number of numerical values in the given record
    Record(const Record &other); //Copy Constructor
    
    //Getters
    vector<string> get_record()
    {
        return record;
    }

    vector<string> get_record() const
    {
        return record;
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
    vector<string> record; //Record with String
    int n; //Number of Strings in the record
};

#endif