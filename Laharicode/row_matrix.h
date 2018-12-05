#ifndef row_matrix_H_
#define row_matrix_H_

#include <iostream>
#include <string>
#include"matrix_main.h"

class row_matrix : public Matrix
{
    private:
        int* permutation_map;
    public:
        row_matrix(int n);
        void mapit(int index,int val);
        Matrix permutate(Matrix M);
};

#endif