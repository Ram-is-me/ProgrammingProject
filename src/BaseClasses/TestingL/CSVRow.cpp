#include "csvrow.h"

istream& operator>>(istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

void CSVRow::readNextRow(istream& str)
{
    string line;
    getline(str, line);

    stringstream   lineStream(line);
    string         cell;

    m_data.clear();
    while(getline(lineStream, cell, ','))
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
