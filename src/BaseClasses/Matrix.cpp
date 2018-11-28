#include "matrix.h"
#include "csvrow.h"
#include "dataset.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

Matrix::Matrix(const int ir , const int ic)
{
    r = ir;
    c = ic;
}

vector<double> Matrix::get_row_i(const int i)
{
    return matrix[i];
}

vector<double> Matrix::get_column_i(const int i)
{
    vector<double> column;
    for(int j=0;j<matrix.size();j++)
    {
        column.push_back(matrix[j][i]);
    }
    return column;
}

void Matrix::fill_data_from_csv(const string filename)
{
    ifstream file(filename);
    CSVRow row;

    string firstLine;
    getline(file, firstLine);

    string temp("");

    int i=0;
    while(firstLine[i]>=48 && firstLine[i]<=57)
    {
        temp+=firstLine[i++];
    }
    cout<<temp<<endl;
    r = stoi(temp);
    i++;
    temp="";
    while(firstLine[i]>=48 && firstLine[i]<=57)
    {
        temp+=firstLine[i++];
    }
    cout<<temp<<endl;
    c = stoi(temp);

    string line;

    stringstream lineStream(line);
    string cell;

    while(file >> row)
    {
        // continue;
        // cout << "4th Element(" << row[3] << ")\n";
        Record *r;
        r = new Record(row.get_vector());
        // for(int i=0;i<row.get_vector().size();i++)
            // cout<<row.get_vector()[i]<<" ";
        cout<<endl;
        // .push_back(*r);
        vector<string> temp1 = r->get_record();
        vector<double> temp2;
        for(int i=0;i<temp1.size();i++)
        {
            temp2.push_back(stod(temp1[i]));
        }
        matrix.push_back(temp2);
        temp2.clear();
    }
}

void Matrix::convert_from_dataset(DataSet &ds)
{
    int n = ds.get_n();
    vector<string> temp1;
    vector<double> temp2;
    for(int i=0;i<ds.no_of_records();i++)
    {
        temp1 = ds.get_data_set()[i].get_record();
        for(int i=n;i<temp1.size();i++)
        {
            temp2.push_back(stod(temp1[i]));
        }
        matrix.push_back(temp2);
        temp2.clear();
    }
    r = matrix.size();
    c = matrix[0].size();
}