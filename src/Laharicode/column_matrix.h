#ifndef column_matrix_H_
#define column_matrix_H_

#include <iostream>
#include <string>
#include "matrix_main.h"

class column_matrix : public Matrix
{   
    private:
        int* permutation_map;
    public:
        column_matrix(int n); // constructor
        void mapit(int index,int val);
        Matrix permutate(Matrix M);
};

#endif