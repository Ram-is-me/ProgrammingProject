#include "task6.h"
#include<iostream>
#include<vector>

// compile it using the command g++ -std=c++11 min_degree_algo.cpp

std::vector<int> min_degree_algo(std::vector<std::vector<double>> matrix)// l is the size of given matrix
 {
   double min_degree = 100;
   int  index_of_min_degree;
   double sum_of_rows[matrix.size()];

   std::vector<int> permutation;
   for(int i = 0 ; i < matrix.size() ; i++)
   {
     double degree = 0;
     for(int j = 0 ; j < matrix.size() ; j++)
     {
       if(i!=j)
       {
          degree = matrix[i][j] + degree;
       }
     }
     sum_of_rows[i] = degree;
   }

  for(int j = 0 ; j < matrix.size() ; j++)
    {
     for(int i = 0 ; i < matrix.size() ; i++ )
       {
        if(min_degree > sum_of_rows[i])
          {
            min_degree = sum_of_rows[i];
            index_of_min_degree = i;
          }
       }
       for(int i = 0 ; i < matrix.size() ; i++)
         {
           sum_of_rows[i] = sum_of_rows[i] - matrix[i][index_of_min_degree];
         }

       sum_of_rows[index_of_min_degree] = 220;
       min_degree = 100;
       permutation.push_back(index_of_min_degree);
    }
   for(int i = 0 ; i < permutation.size() ; i++)
      std::cout<<" "<<permutation[i]<<" ";
      std::cout<<std::endl;
   return permutation;
 }
