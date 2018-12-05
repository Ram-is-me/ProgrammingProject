#ifndef matrix_main_H
#define matrix_main_H
#include <vector>
#include <string>
#include "matrix.h"
// #include "dataset.h"
using namespace std;

class Matrixm : public Matrix
{
    public:
    Matrixm(int ir = 100, int ic = 100);

    Matrixm(int rows, int cols,double** vals);//
    void set_matrix(double** m);//
    double** getIndentity(int n);//
    int getrows();//
    int getcolumns();//
    Matrixm multiplication(Matrixm M1, Matrixm M2);//
    int get_row_index(double value);//
    int get_column_index(double value);//
    double get_max_of_upper();//
    int get_max_of_row(int row);//
    int get_max_of_column(int column);//
    double get_max_of_index(int index);//
    double** get_my_matrix();//

    Matrixm& operator= (const Matrixm & M);//
    // {
    // return my_matrix;
    // }

    friend ostream& operator<<(ostream &os,const Matrixm &m);//

    

    protected:
    int r;
    int c;
    vector< vector<double> > matrix;
    double** my_matrix;
};

#endif