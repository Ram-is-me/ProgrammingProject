#include "matrix.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

Matrix::Matrix(const int ir , const int ic )
{
    r = ir;
    c = ic;
    matrix.resize(r);
    for(int i=0;i<r;i++)
    {
        matrix[i].resize(c);
    }
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
    
}

