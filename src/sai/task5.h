#ifndef TASK5_H
#define TASK5_H
#include <vector>
#include <string>
#include<iostream>
#include <math.h>
#include "matrix.h"
#include <time.h>
using namespace std;

vector< vector<double> > matrix_mul(vector< vector<double> > a,vector< vector<double> > b);
vector< vector<double> > mat_transpose(vector< vector<double> > a);
vector< vector<double> > mat_transpose(vector<double>  a);
double norm(vector< vector<double> > a);
vector< vector<double> > multiply_scalar(vector< vector<double> > a,double k);
vector< vector<double> > division_scalar(vector< vector<double> > a,double k);
vector< vector<double> > subtract_scalar(vector< vector<double> > a,double k);
vector< vector<double> > sum_scalar(vector< vector<double> > a,double k);
vector< vector<double> > random_init(int ax,int ay);
vector< vector<double> > matrix_subtract(vector< vector<double> >a,vector< vector<double> >b);
vector< vector<double> > power_itration(Matrix S,int k);
vector<double> get_evalues(vector< vector<double> > a);
#endif