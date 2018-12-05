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
    bool row_direction;
    index++;
    int max_rows = M.get_max_of_column(index);
    int max_columns = M.get_max_of_row(index);

    if(M.get_matrix()[M.get_max_of_column(index)][index] > M.get_matrix()[index][M.get_max_of_row(index)])
    {
        row_direction = true;
        matrix_R.mapit(index,M.get_max_of_column(index));
        M = matrix_R.permutate(M);
    }
    else
    {
        row_direction = false;
        matrix_C.mapit(index,M.get_max_of_row(index));
        M = matrix_C.permutate(M);
    }
    // M = permutate(matrix_R,matrix_C,initialMatrix);
    int row_index = 2;
    int column_index = 2;
    index++;
    while(row_index < rows || column_index < rows)
    {
        if(row_direction)
        {
            max = M.get_max_of_column(row_index);
            matrix_R.mapit(row_index,max);
            M = matrix_R.permutate(M);
            row_index++;
        }
        else
        {
            max = M.get_max_of_row(column_index);
            matrix_C.mapit(column_index,max);
            M = matrix_C.permutate(M);
            column_index++;
        }
        // M = permutate(matrix_R,matrix_C,initialMatrix);
        row_direction = !row_direction;
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
