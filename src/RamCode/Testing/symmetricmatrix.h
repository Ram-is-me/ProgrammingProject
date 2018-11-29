#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H
#include "matrix.h"
#include <vector>
#include <string>
using namespace std;
class SymmetricMatrix : public Matrix
{
    public:
    SymmetricMatrix(int is);  //Constructor
    SymmetricMatrix(const SymmetricMatrix &other); //Copy Constructor
    private:
};

#endif