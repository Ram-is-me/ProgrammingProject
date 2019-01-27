#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include "matrix.h"
#include "symmetric.h"
using namespace std;

void print(float** a,int ax,int ab)
{
    int i1,i2;
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ab;i2++)
        {
            cout<<a[i1][i2]<<" ";
        }
        cout<<endl;
    }    
    cout<<endl;
}
int main()
{
    symmetric m1(5);
    int i1,i2;
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            m1.set_xy(i1,i2,i1+i2);
            cout<<i1+i2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    float **temp;
    temp=m1.power_itration(m1.get_mat(),m1.get_x(),5);
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            cout<<temp[i1][i2]<<" ";
        }
        cout<<endl;
    }
    float **temp1;
    temp1=m1.mat_transpose(temp[1],5);
    print(temp1,5,1);
    float **temp2;
    temp2=m1.mat_mul(m1.get_mat(),temp1,5,5,5,1);
    print(temp2,5,1);
    cout<<endl;
    for(i1=0;i1<5;i1++)
    {
        cout<<"asdf  "<<(float)temp2[i1][0]/(float)temp1[i1][0]<<endl;
    }
    cout<<endl;
}