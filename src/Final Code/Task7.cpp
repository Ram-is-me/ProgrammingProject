#include"symmetricmatrix.h"
#include <queue>
#include "task7.h"
#include<bits/stdc++.h>

using namespace std;


Task7::Task7(){}

// makes an sparcified version of the symmetric matrix 

void Task7::sparcify()
{
    for(int i=0;i<sym_mat.get_row_size();i++)
    {
        for(int j=0;j<sym_mat.get_column_size();j++)
        {
            if(sym_mat.get_value(i, j) < 0.75)
            {
                sym_mat.set_value(i, j, 0);
            }
            else
            {
                sym_mat.set_value(i, j, 1);
            }
        }
    }
}

// makes a vector of the degree of each index
vector<int> Task7::compute_degree_vector()
{
    vector<int> degree_vector;
    for(int i=0;i<sym_mat.get_row_size();i++)
    {
        int deg = 0;
        for(int j=0;j<sym_mat.get_column_size();j++)
        {
            deg += sym_mat.get_value(i,j);
        }
        degree_vector.push_back(deg);
    }
    return degree_vector;
}

// checks if two nodes are neighbors or not
int Task7::is_neighbor(int node1,int node2)
{
    if(sym_mat.get_value(node1,node2) == 1)
    {
        return 1;
    }
    else 
        return 0;
}

int Task7::find_index_with_minimum_degree(vector<int> min_deg_vec)
{
    int min = -1;
    int row_with_min_degree;
    for(int i=0;i<min_deg_vec.size();i++)
    {
        if(min_deg_vec.at(i) != -1)
        {
            if(min == -1)
            {
                min = min_deg_vec.at(i);
                row_with_min_degree = i;
            }
            else if(min_deg_vec.at(i) < min)
            {
                min = min_deg_vec.at(i);
                row_with_min_degree = i;
            }
        }
    }

    return row_with_min_degree;
}

//compares degrees of two nodes
bool comparedegree(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second < b.second;
}

//helper function
int Task7::add(vector<int> degrees)
{
    int sum=0;
    for(int i=0;i<degrees.size();i++)
    {
        sum += degrees.at(i);
    }
    return sum;
}

//function to add neighbors (of the element added to R) to Q 
void Task7::add_neighbors(vector<int> degree_vec,int row)
{
    vector<pair<int,int>> elements_adding_to_Q;
    for(int i=0;i<degree_vec.size();i++)
    {
        if(i != row && degree_vec.at(i) != -1)
        {
            if(is_neighbor(row,i))
            {
                elements_adding_to_Q.push_back(make_pair(i,degree_vec.at(i)));
            }
        }
    }    

    sort(elements_adding_to_Q.begin(),elements_adding_to_Q.end(),comparedegree);

    for(int i=0;i<elements_adding_to_Q.size();i++)
    {
        Q.push(elements_adding_to_Q.at(i).first);
    }
}

void Task7::reverse_cuthill_mckee(string input_file)
{
    int flag=0;
    sym_mat.fill_data_from_csv(input_file);
    sparcify();
    vector <int> degree_vec = compute_degree_vector();
    
    while(flag !=  sym_mat.get_row_size()* -1)
    {
        int min_degree_row = find_index_with_minimum_degree(degree_vec);
        R.push_back(min_degree_row);
        add_neighbors(degree_vec,min_degree_row);
        degree_vec.at(min_degree_row) = -1;           //suggests that it is deleted from the degree vector
        while(Q.empty() != 1)
        {
            int row = Q.front();
            int check = 0;
            Q.pop();
            R.push_back(row);
            add_neighbors(degree_vec,row);
            degree_vec.at(min_degree_row) = -1;
        } 
        flag = add(degree_vec);
            
    }
    reverse(R.begin(),R.end());

    for(int i=0;i<R.size();i++)
    {
        cout<<R.at(i);
    }
 
}   