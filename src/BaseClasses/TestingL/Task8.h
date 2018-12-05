#ifndef TASK8_H_
#define TASK8_H_

#include"row_matrix.h"
#include"column_matrix.h"

class robin_algo
{
    protected:
        int rows;
        Matrixm M;
        column_matrix matrix_C;
        row_matrix matrix_R;
    public:
        robin_algo(Matrixm M);
        Matrixm permutate(row_matrix matrix_R, column_matrix matrix_C, Matrixm M);
        void create();
        Matrixm get_final_matrix();
        void final_fun(Matrixm M);
};

#endif