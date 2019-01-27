#include "matrix.h"
using namespace std;
matrix::matrix(int a,int b)
{
    x=a;
    y=b;
    mat = new float*[x];
    int i;
    for(i=0;i<x;i++)
    {
        mat[i] = new float[y];
    }
}
void matrix::set_xy(int a,int b,float c)
{
    mat[a][b]=c;
}
float matrix::get_xy(int a,int b)
{
    return mat[a][b];
}
float ** matrix::get_mat()
{
    return mat;
}
int matrix::get_x()
{
    return x;
}
int matrix::get_y()
{
    return y;
}
float** matrix::mat_mul(float** a,float** b,int ax,int ay,int bx,int by)
{
    int i1,i2,i3;
    float** temp;
    temp = new float*[ax];
    int i;
    for(i=0;i<ax;i++)
    {
        temp[i] = new float[by];
    }
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<by;i2++)
        {
            temp[i1][i2]=0;
        }
    }
    if(ay==bx)
    {
        for(i1=0;i1<ax;i1++)
        {
            for(i2=0;i2<by;i2++)
            {
                for(i3=0;i3<ay;i3++)
                {
                    temp[i1][i2] += a[i1][i3]*b[i3][i2];
                }
            }
        }
    }
    return temp;
}
float **matrix::mat_transpose(float** a,int ax,int ay)
{
    int a_x=ay;
    int a_y=ax;
    float** temp;
    temp = new float*[ay];
    int i;
    for(i=0;i<a_x;i++)
    {
        temp[i] = new float[ax];
    }
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            temp[i2][i1]=a[i1][i2];
        }
    }
    return temp;
}
float matrix::norm(float* a,int x)
{
    float temp=0;
    int i;
    for(i=0;i<x;i++)
    {
    // cout<<"innor  "<<a[i]<<endl;
        temp=temp+a[i]*a[i];
    }
    temp=pow(temp,0.5);
    return temp;
}
float** matrix::multiply_scalar(float** a,float b,int ax,int ay)
{
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            a[i1][i2]=a[i1][i2]*b;
        }
    }
    return a;
}
void matrix::division_scalar(float** a,float b,int ax,int ay)
{
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            // cout<<"insub  "<<b<<endl;
            if(b!=0)
            {
                a[i1][i2]=a[i1][i2]/b;
            }
        }
    }
}
void matrix::subtract_scalar(float** a,float b,int ax,int ay)
{
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            a[i1][i2]=a[i1][i2]-b;
        }
    }
}
void matrix::sum_scalar(float** a,float b,int ax,int ay)
{
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            a[i1][i2]=a[i1][i2]+b;
        }
    }
}
void matrix::random_init(float**a,int ax,int ay)
{
    rand();
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            a[i1][i2]=rand()%100+1;
        }
    }
}
void matrix::subtract_matrix(float **a,float** b,int ax,int ay,int bx,int by)
{
    if(ax==bx && by==ay)
    {
        int i1,i2;
        for(i1=0;i1<ax;i1++)
        {
            for(i2=0;i2<ay;i2++)
            {
                a[i1][i2]=a[i1][i2]-b[i1][i2];
            }
        }
    }
}
float** matrix::mat_transpose(float* a,int ax)
{
    float** temp;
    temp = new float*[ax];
    int i;
    for(i=0;i<ax;i++)
    {
        temp[i] = new float[0];
    }
    for(i=0;i<ax;i++)
    {
        temp[i][0]=a[i];
        // cout<<"intransp  "<<<<endl;
    }
    return temp;
} 