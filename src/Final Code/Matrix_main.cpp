#include "matrix_main.h"
// #include "csvrow.h"
// #include "dataset.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

Matrixm::Matrixm(const int ir , const int ic)
{
    r = ir;
    c = ic;
}

//to initialize with values
Matrixm::Matrixm(int rows,int cols,double** values)
{
    this->r = rows;
    this->c = cols;
    my_matrix = new double*[rows];
      for(int i=0;i<rows;i++)
      {
        my_matrix[i] = new double[cols];
      }
      this->set_matrix(values);
}

//to set the matrix with the values of given matrix
void Matrixm::set_matrix(double** _matrix)
{
  for(int i  = 0;i < r; i++)
  {
    for(int j = 0;j < c;j++)
    {
        my_matrix[i][j] = _matrix[i][j];
    }
  }
}

//creates a identity matrix of size n
double** Matrixm::getIndentity(int n)
{
    double** values = new double*[n];
    for(int i=0;i<n;i++)
    {
        values[i] = new double[n];
        for(int j=0;j<n;j++){
            if(i==j) values[i][j] = 1;
            else values[i][j] = 0;
        }
    }
    return values;
}

//returns the no of rows
int Matrixm::getrows()
{
  return this->r;
}

//returns the no of columns
int Matrixm::getcolumns()
{
  return this->c;
}

Matrixm Matrixm::multiplication(Matrixm M1, Matrixm M2)
{
    //initialize
    double** values_of_product = new double*[M1.getrows()];
    for(int i=0;i<M1.getrows();i++)
    {
        values_of_product[i] = new double[M2.getcolumns()];
        for(int j=0;j<M2.getcolumns();j++)
        {
            values_of_product[i][j] = 0;
        }
    }
    //multiplication part
    if(M1.getcolumns() == M2.getrows())
    {
        for(int i=0;i<M1.getrows();i++)
        {
            for(int j=0;j<M2.getcolumns();j++)
            {
                for(int k=0;k<M1.getcolumns();k++)
                {
                    values_of_product[i][j] = values_of_product[i][j] + ((M1.get_matrix()[i][k]) * (M2.get_matrix()[k][j]));
                }
            }   
        }
    }
    Matrixm product_matrix(M1.getrows(),M2.getcolumns(),values_of_product);
    return product_matrix;
}

//returns max value in the upper triangle 
double Matrixm::get_max_of_upper()
{
  double max = this->matrix[0][0];
  for(int i=0;i<r;i++)
  {
      for(int j=i;j<c;j++)
      {
        if(my_matrix[i][j] > max) 
        {
            max = my_matrix[i][j];
        }
      }
  }
  return max;
}

// gives the row index in which the value is present
int Matrixm::get_row_index(double value)
{
    for(int i=0;i< r; i++)
    {
        for(int j=0;j < c;j++)
        {
            if(my_matrix[i][j]==value)
            {
                return i;
            }
        }
    }
    return -1;
}

// gives the column index in which the value is present
int Matrixm::get_column_index(double value)
{
    for(int i=0;i< r; i++)
    {
        for(int j=0;j < c;j++)
        {
            if(my_matrix[i][j]==value)
            {
                return j;
            }
        }
    }
    return -1;
}

//
int Matrixm::get_max_of_column(int column)
{
    int max = column;
    for(int i=column;i<r;i++)
    {
        if(my_matrix[i][column] > my_matrix[max][column])
        {
            max = i;
        } 
    }
    return max;
}

//
int Matrixm::get_max_of_row(int row){
    int max = row;
    for(int i=row;i<c;i++)
    {
        if(my_matrix[row][i] > my_matrix[row][max])
        {
            max = i;
        } 
    }
    return max;
}

//
double Matrixm::get_max_of_index(int index)
{
    double maxFromRows = matrix[this->get_max_of_row(index)][index];
    double maxFromCols = matrix[index][this->get_max_of_column(index)];
    if(maxFromCols > maxFromRows) 
    {
        return maxFromCols;
    }
    else
    {
        return maxFromRows;
    } 
}

double** Matrixm::get_my_matrix()
{
  return my_matrix;
}

ostream& operator<<(ostream &os,const Matrixm &m) 
{
  for (int i = 0 ; i < m.r; i++)
    {
      for(int j = 0; j < m.c; j++)
        {
          os<<m.my_matrix[i][j]<<" ";
        }
        os <<endl ;
    }
  return os ;
}


Matrixm& Matrixm::operator= (const Matrixm & M)
{
    r = M.r;
    c = M.c;
    my_matrix = new double*[r] ;
    for (int i = 0 ; i < r ; i++) 
    {
        my_matrix[i] = new double[c] ;
        for(int j=0;j<c;j++) 
        {
            my_matrix[i][j] = M.my_matrix[i][j];
        }
    }
    return *this;
}
