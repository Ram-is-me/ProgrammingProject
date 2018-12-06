#ifndef TASK8_H_
#define TASK8_H_

#include"row_matrix.h"
#include"column_matrix.h"

class Task8
{
    protected:
        int rows;
        Matrixm M;
        column_matrix matrix_C;
        row_matrix matrix_R;
    public:
        Task8(Matrixm M);
        Matrixm permutate(row_matrix matrix_R, column_matrix matrix_C, Matrixm M);
        void diagonals();
        Matrixm get_final_matrix();
        // void final_fun(Matrix M);
};

#endif
