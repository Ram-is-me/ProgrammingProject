#ifndef robin_algo_H_
#define robin_algo_H_

#include"row_matrix.h"
#include"column_matrix.h"

class robin_algo
{
    private:
        int rows;
        Matrix M;
        column_matrix matrix_C;
        row_matrix matrix_R;
    public:
        robin_algo(Matrix M);
        Matrix permutate(row_matrix matrix_R, column_matrix matrix_C, Matrix M);
        void create();
        Matrix get_final_matrix();
};

#endif