#include"symmetricmatrix.h"
#include <queue>

void reverse_cuthill_mckee(SymmetricMatrix sym_mat, vector <int> int_vec)
{
    int rows = sym_mat.get_row_size();
    int columns = sym_mat.get_column_size();
    SymmetricMatrix sm = sym_mat;
    vector <int> degree_order = int_vec;

    queue <int> Q;
    vector <int> R;
    int visited[rows];


    for(int i = 0; i < rows; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(sym_mat.get_value(i, j) < 0.75)
            {
                sm.set_value(i, j, 0);
            }
            else
            {
                sm.set_value(i, j, 1);
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        int row_no = int_vec[i];
        if(visited[row_no] == 1)
        {
            continue;
        }
        else
        {
            visited[row_no] = 1;
            R.push_back(row_no);
            for(int j = 0; j < columns; j++)
            {
                
            }
        }


    }
}