#include "symmetric.h"
using namespace std;
symmetric::symmetric(int a):matrix(a,a)
{

}
void symmetric::set_xy(int a,int b,float c)
{
    mat[a][b]=c;
    mat[b][a]=c;
}

float** symmetric::power_itration(float** S,int Sx,int k)
{
    float** temp;
    int i1,i2,i3;
    //initializarion of temp
    temp = new float*[x];
    int i;
    for(i=0;i<x;i++)
    {
        temp[i] = new float[x];
    }
    for(i1=0;i1<x;i1++)
    {
        for(i2=0;i2<x;i2++)
        {
            temp[i1][i2]=0;
        }
    }
    //done init collection of temp
    float** temp1;
    temp1=new float*[x];
    for(i=0;i<x;i++)
    {
        temp1[i]=new float[1];
    }
    //start
    // cout<<"iwruiewuufewiefwjiioew   "<<endl;
    const float E=0.001;
    for(i1=0;i1<k;i1++)
    {
        random_init(temp1,x,1);
        int nor=norm(mat_transpose(temp1,x,1)[0],x);
        division_scalar(temp1,nor,x,1);

        do{
            for(i2=0;i2<i1-1;i2++)
            {
                subtract_matrix(temp1,multiply_scalar(mat_transpose(temp[i2],x),mat_mul(mat_transpose(temp1,x,1),mat_transpose(temp[i2],x),1,x,x,1)[0][0],x,1),x,1,x,1);
            }
            temp1=mat_mul(S,temp1,Sx,Sx,x,1);
            nor=norm(mat_transpose(temp1,x,1)[0],x);
            // cout<<"222222222    "<<nor;
            division_scalar(temp1,nor,x,1);
        }while(mat_mul(mat_transpose(temp1,x,1),temp1,1,x,x,1)[0][0]<1-E);
        for(i3=0;i3<x;i3++)
        {
            temp[i1][i3]=temp1[i3][0];
        }
    }
    return temp;
}