#include "task5.h"

vector< vector<double> > matrix_mul(vector< vector<double> > a,vector< vector<double> > b)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<b[0].size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    if(a[0].size()==b.size())
    {
        for(i1=0;i1<a.size();i1++)
        {
            for(i2=0;i2<b[0].size();i2++)
            {
                for(i3=0;i3<a[0].size();i3++)
                {
                    temp[i1][i2] += a[i1][i3]*b[i3][i2];
                }
            }
        }
    }
    return temp;
}

vector< vector<double> > mat_transpose(vector< vector<double> > a)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a[0].size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<a.size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<temp.size();i1++)
    {
        for(i2=0;i2<temp[0].size();i2++)
        {
            temp[i1][i2]=a[i2][i1];
        }
    }
    return temp;
}

vector< vector<double> > mat_transpose(vector<double>  a)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<1;i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<temp.size();i1++)
    {
        temp[i1][0]=a[i1];
    }
    return temp;
}
double norm(vector< vector<double> > a)
{
    double temp=0;
    if(a[0].size()==1)
    {
        int i;
        for(i=0;i<a.size();i++)
        {
            temp=temp+a[i][0]*a[i][0];
        }
        temp=pow(temp,0.5);
    }
    return temp;
}

vector< vector<double> > multiply_scalar(vector< vector<double> > a,double k)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<a[0].size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<a.size();i1++)
    {
        for(i2=0;i2<a[0].size();i2++)
        {
            temp[i1][i2]=a[i1][i2]*k;
        }
    }
    return temp;
}

vector< vector<double> > division_scalar(vector< vector<double> > a,double k)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<a[0].size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<a.size();i1++)
    {
        for(i2=0;i2<a[0].size();i2++)
        {
            temp[i1][i2]=a[i1][i2]/k;
        }
    }
    return temp;
}

vector< vector<double> > subtract_scalar(vector< vector<double> > a,double k)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<a[0].size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<a.size();i1++)
    {
        for(i2=0;i2<a[0].size();i2++)
        {
            temp[i1][i2]=a[i1][i2]-k;
        }
    }
    return temp;
}

vector< vector<double> > sum_scalar(vector< vector<double> > a,double k)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<a.size();i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<a[0].size();i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<a.size();i1++)
    {
        for(i2=0;i2<a[0].size();i2++)
        {
            temp[i1][i2]=a[i1][i2]+k;
        }
    }
    return temp;
}

vector< vector<double> > random_init(int ax,int ay)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    for(i1=0;i1<ax;i1++)
    {
        vector<double> temp1;
        for(i2=0;i2<ay;i2++)
        {
            temp1.push_back(0);
        }
        temp.push_back(temp1);
    }
    for(i1=0;i1<ax;i1++)
    {
        for(i2=0;i2<ay;i2++)
        {
            temp[i1][i2]=rand()%100+1;
            // cout<<temp[i1][i2]<<" ";
        }
    }
    return temp;
}

vector< vector<double> > matrix_subtract(vector< vector<double> >a,vector< vector<double> >b)
{
    vector< vector<double> > temp;
    int i1,i2,i3;
    if(a.size()==b.size() && a[0].size()==b[0].size())
    {
        for(i1=0;i1<a.size();i1++)
        {
            vector<double> temp1;
            for(i2=0;i2<a[0].size();i2++)
            {
                temp1.push_back(0);
            }
            temp.push_back(temp1);
        }
        for(i1=0;i1<a.size();i1++)
        {
            for(i2=0;i2<a[0].size();i2++)
            {
                temp[i1][i2]=a[i1][i2]-b[i1][i2];
            }
        }
    }
    return temp;
}

vector< vector<double> > power_itration(Matrix S,int k,vector<double>& value)
{
    int i1,i2,i3;
    Matrix temp(S.get_row_size(),S.get_column_size());
    temp.re_size(S.get_row_size(),S.get_column_size());
    for(i1=0;i1<S.get_row_size();i1++)
    {
        vector<double> temp2;
        for(i2=0;i2<S.get_column_size();i2++)
        {
            temp2.push_back(0);
        }
        temp.get_matrix().push_back(temp2);
    }    
    vector< vector<double> >temp1;  
    const double E=0.001;
    for(i1=0;i1<k;i1++)
    {
        temp1=random_init(S.get_row_size(),1);
        double nor=norm(temp1);
        temp1=division_scalar(temp1,nor);
        do{
            for(i2=0;i2<i1-1;i2++)
            {
                temp1=matrix_subtract(temp1,multiply_scalar(mat_transpose(temp.get_row_i(i2)),matrix_mul(mat_transpose(temp1),mat_transpose(temp.get_row_i(i2)))[0][0]));
            }
            temp1=matrix_mul(S.get_matrix(),temp1);
            nor=norm(temp1);
            value.push_back(nor);
            temp1=division_scalar(temp1,nor);
        }while(matrix_mul(mat_transpose(temp1),temp1)[0][0]<1-E);
        for(i3=0;i3<S.get_row_size();i3++)
        {
            temp.set_value(i1,i3,temp1[i3][0]);
        }
    }
    return temp.get_matrix();
}




