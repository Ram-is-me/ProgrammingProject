#include "task5.h"

Task5::Task5(string filename)
{
    S.fill_data_from_csv(filename);
}
vector< vector<double> >Task5::matrix_mul(vector< vector<double> > a,vector< vector<double> > b)
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

vector< vector<double> > Task5::mat_transpose(vector< vector<double> > a)
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

vector< vector<double> > Task5::mat_transpose(vector<double>  a)
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
double Task5::norm(vector< vector<double> > a)
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

vector< vector<double> > Task5::multiply_scalar(vector< vector<double> > a,double k)
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

vector< vector<double> > Task5::division_scalar(vector< vector<double> > a,double k)
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

vector< vector<double> > Task5::subtract_scalar(vector< vector<double> > a,double k)
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

vector< vector<double> > Task5::sum_scalar(vector< vector<double> > a,double k)
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

vector< vector<double> > Task5::random_init(int ax,int ay)
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

vector< vector<double> > Task5::matrix_subtract(vector< vector<double> >a,vector< vector<double> >b)
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
void Task5::cpy(vector< vector<double> >& from,vector< vector<double> >& to)
{
    int i1,i2;
    for(i1=0;i1<from.size();i1++)
    {
        for(i2=0;i2<from[0].size();i2++)
        {
            to[i1][i2]=from[i1][i2];
        }
    }
}
void Task5::power_itration(int k)
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
    vector< vector<double> >temp1,temp3;  
    const double E=0.001;
    for(i1=0;i1<k;i1++)
    {
        double y=0,k=0;
        temp1=random_init(S.get_row_size(),1);//ui
        temp3=random_init(S.get_row_size(),1);//uic
        double nor=norm(temp3);
        temp3=division_scalar(temp3,nor);
        do{
            cpy(temp3,temp1);
            y=k;
            k=0;
            for(i2=0;i2<=i1-1;i2++)
            {
                temp1=matrix_subtract(temp1,multiply_scalar(mat_transpose(temp.get_row_i(i2)),matrix_mul(mat_transpose(temp1),mat_transpose(temp.get_row_i(i2)))[0][0]));
            }
            temp3=matrix_mul(S.get_matrix(),temp1);
            nor=norm(temp3);
            k=nor;
            temp3=division_scalar(temp3,nor);
        }while(fabs(k-y)>0.0001);
        value.push_back(nor);
        for(i3=0;i3<temp3.size();i3++)
        {
            temp.set_value(i1,i3,temp3[i3][0]);
        }
    }
    vectors=temp;
}
void Task5::output_to_csv(const string filename)
{
    ofstream file(filename);

    file<<S.get_row_size()<<" "<<S.get_column_size()<<endl;
    for(int i=0;i<vectors.get_row_size();i++)
    {
        for(int j=0;j<vectors.get_column_size();j++)
        {
            file<<vectors.get_matrix()[i][j]<<";";
        }
        file<<"value = "<<value[i]<<endl;
    }
}




