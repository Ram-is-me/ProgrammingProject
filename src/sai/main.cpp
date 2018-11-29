#include<iostream>
#include <vector>
#include <string>
#include "dataset.h"
#include "task5.h"
#include "matrix.h"
using namespace std;
int main()
{
    // Matrix mat(3,3);
    // mat.re_size(3,3);
    task5 task("input.csv");
    int i1,i2;
    // for(i1=0;i1<3;i1++)
    // {
    //     for(i2=0;i2<3;i2++)
    //     {
    //         mat.set_value(i1,i2,i1+i2);
    //     }
    // }
    // for(i1=0;i1<3;i1++)
    // {
    //     for(i2=0;i2<3;i2++)
    //     {
    //         cout<<mat.get_matrix()[i1][i2]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<double> value;
    task.power_itration(3);
    task.output_to_csv("output.csv");
}