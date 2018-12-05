#ifndef TASK5_H
#define TASK5_H
#include <vector>
#include <string>
#include<iostream>
#include <math.h>
#include "matrix.h"
#include <time.h>
#include<string>
#include <fstream>
using namespace std;
class task5
{
    private:
    Matrix S;
    Matrix vectors;
    vector<double> value;
    vector< vector<double> > matrix_mul(vector< vector<double> > a,vector< vector<double> > b);
    vector< vector<double> > mat_transpose(vector< vector<double> > a);
    vector< vector<double> > mat_transpose(vector<double>  a);
    double norm(vector< vector<double> > a);
    vector< vector<double> > multiply_scalar(vector< vector<double> > a,double k);
    vector< vector<double> > division_scalar(vector< vector<double> > a,double k);
    vector< vector<double> > subtract_scalar(vector< vector<double> > a,double k);
    vector< vector<double> > sum_scalar(vector< vector<double> > a,double k);
    vector< vector<double> > random_init(int ax,int ay);
    void cpy(vector< vector<double> >&,vector< vector<double> >&);
    vector< vector<double> > matrix_subtract(vector< vector<double> >a,vector< vector<double> >b);
    public:
    task5(string filename);
    void power_itration(int k);
    void output_to_csv(string );
    };
#endif