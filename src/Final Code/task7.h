#ifndef TASK7_H
#define TASK7_H

#include"symmetricmatrix.h"
#include <queue>

class Task7
{
    private:
    SymmetricMatrix sym_mat;
    queue <int> Q;
    vector <int> R;

    public:
    Task7();
    void sparcify();
    vector<int> compute_degree_vector();
    int is_neighbor(int n1,int n2);
    int find_index_with_minimum_degree(vector<int>);
    void add_neighbors(vector<int>,int);

    int add(vector<int>);
    void reverse_cuthill_mckee(string input_file);

};

#endif