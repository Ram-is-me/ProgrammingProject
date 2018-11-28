#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string filename;
    // cin>>filename;
    Matrix m; 
    m.fill_data_from_csv("input.csv");
    int r = m.get_row_size();
    int c = m.get_column_size();
    cout<<endl<<r<<" "<<c<<endl;
    vector<vector<double>> temp = m.get_matrix();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c-1;j++)
        {
            // cout<<m.get_row_i(i)[j]<<", ";
            cout<<temp[i][j]<<", ";
        }
        cout<<temp[i][c-1]<<endl;
        // cout<<m.get_row_i(i)[c-1]<<"\n";
    }
    return 0;
}