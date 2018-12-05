#include "row_matrix.h"
#include "column_matrix.h"
#include "robin_algo.h"

#include <bits/stdc++.h>
using namespace std;

robin_algo::robin_algo(Matrix M)
{
    rows = M.getrows();
    matrix_R = row_matrix(rows);
    matrix_C = column_matrix(rows);
}

Matrix robin_algo::permutate(row_matrix matrix_R, column_matrix matrix_C, Matrix M)
{
    // this->setValues(getIndentity(this->getCols()));
    M = matrix_R.permutate(M);
    M = matrix_C.permutate(M);
    return M;
}

void robin_algo::create()
{

    int index = 0;
    int max = M.get_max_of_upper();

    matrix_R.mapit(index,M.get_row_index(max));
    matrix_C.mapit(index,M.get_column_index(max));

    M = permutate(matrix_R,matrix_C,M);

    max = M.get_max_of_index(index);
    bool rowDirection;
    index++;
    int maxFromRows = M.get_max_of_column(index);
    int maxFromCols = M.get_max_of_row(index);
    if(M.get_matrix()[M.get_max_of_column(index)][index] > M.get_matrix()[index][M.get_max_of_row(index)])
    {
        rowDirection = true;
        matrix_R.mapit(index,M.get_max_of_column(index));
        M = matrix_R.permutate(M);
    }
    else
    {
        rowDirection = false;
        matrix_C.mapit(index,M.get_max_of_row(index));
        M = matrix_C.permutate(M);
    }
    // M = permutate(matrix_R,matrix_C,initialMatrix);
    int rowIndex = 2;
    int colIndex = 2;
    index++;
    while(rowIndex < rows || colIndex < rows)
    {
        if(rowDirection)
        {
            max = M.get_max_of_column(rowIndex);
            matrix_R.mapit(rowIndex,max);
            M = matrix_R.permutate(M);
            rowIndex++;
        }
        else
        {
            max = M.get_max_of_row(colIndex);
            matrix_C.mapit(colIndex,max);
            M = matrix_C.permutate(M);
            colIndex++;
        }
        // M = permutate(matrix_R,matrix_C,initialMatrix);
        rowDirection = !rowDirection;
    }
}

Matrix robin_algo::get_final_matrix()
{
    return M;
}

void robin_algo::final_fun(Matrix M)
{
    this->robin_algo(M);
    this->permutate(matrix_R,matrix_C,M);
    this->create();
    this->get_final_matrix();
}