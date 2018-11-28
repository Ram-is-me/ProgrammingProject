#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<math.h>
using namespace std;
class matrix
{
    protected:
    int x,y;
    float **mat;
    public:
    matrix(int a,int b);
    void set_xy(int a,int b,float c);
    float get_xy(int a,int b);
    float** get_mat();
    int get_x();
    int get_y();
    float **mat_transpose(float **,int,int);
    float **mat_transpose(float *,int);
    float ** mat_mul(float** a,float** b,int ax,int ay,int bx,int by);
    float norm(float* a,int x);
    float** multiply_scalar(float** a,float b,int ax,int ay);
    void division_scalar(float** a,float b,int ax,int ay);
    void subtract_scalar(float** a,float b,int ax,int ay);
    void sum_scalar(float** a,float b,int ax,int ay);
    void subtract_matrix(float** a,float** b,int ax,int ay,int bx,int by);
    void random_init(float** a,int ax,int ay);
};
#endif