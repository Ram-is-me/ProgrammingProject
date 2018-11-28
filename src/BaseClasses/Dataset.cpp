#include "dataset.h"
#include <fstream>
#include <string>
#include <sstream>

class CSVRow
{
    public:
        string const& operator[](size_t index) const
        {
            return m_data[index];
        }
        size_t size() const
        {
            return m_data.size();
        }
        void readNextRow(istream& str)
        {
            string         line;
            getline(str, line);

            stringstream   lineStream(line);
            string         cell;

            m_data.clear();
            while(getline(lineStream, cell, ';'))
            {
                m_data.push_back(cell);
            }
            // This checks for a trailing comma with no data after it.
            if (!lineStream && cell.empty())
            {
                // If there was a trailing comma then add an empty element.
                m_data.push_back("");
            }
        }
        vector<string> get_vector()
        {
            return m_data;
        }
        vector<string> get_vector() const
        {
            return m_data;
        }
    private:
        vector<string> m_data;
};

istream& operator>>(istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

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