#ifndef SYMMETRIC_H
#define SYMMETRIC_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include <time.h>
#include <math.h>
#include "matrix.h"
using namespace std;
class symmetric: public matrix 
{
    public:
    symmetric(int a);
    virtual void set_xy(int a,int b,float c);
    float ** power_itration(float**S,int sx,int k);
};
#endif