#include<iostream>
#include <vector>
#include <string>
#include "dataset.h"
#include "task5.h"
#include "matrix.h"
using namespace std;
int main()
{
    Matrix mat(5,5);
    mat.re_size(5,5);
    int i1,i2;
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            mat.set_value(i1,i2,i1+i2);
        }
    }
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            cout<<mat.get_matrix()[i1][i2]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<double>> temp=power_itration(mat,5);
    for(i1=0;i1<5;i1++)
    {
        for(i2=0;i2<5;i2++)
        {
            cout<<temp[i1][i2]<<" ";
        }
        cout<<endl;
    }
    vector<double> temp1= get_evalues(temp);
    for(i1=0;i1<temp1.size();i1++)
    {
        cout<<endl<<temp1[i1]<<" ";
    }
    cout<<endl;
}