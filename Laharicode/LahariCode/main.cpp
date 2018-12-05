#include "robin_algo.h"
#include <stdio.h>
#include <time.h>

#include <bits/stdc++.h>

int main()
{
    int n = 10;
    int index = 0;
    srand((unsigned int)time(NULL));
    double** values = new double*[n];
    for(int i=0;i<n;i++){
        values[i] = new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            values[i][j] = rand()%10;
            values[j][i] = values[i][j];
        }
    }
    Matrix M(n,n,values);
    cout << M;
    cout << endl;
    robin_algo R(M);
    R.create();
    M = R.get_final_matrix();
    // R.final_fun(M);
    cout << M;
    return 0;


    // Matrix M(n,n,values);
    // cout << M;
    // cout << endl;
    // Robinsonian R(M);
    // R.create();
    // M = R.getMatrix();
    // cout << M;
    // return 0;
}