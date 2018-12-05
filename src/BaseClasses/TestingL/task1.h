#ifndef TASK1_H_
#define TASK1_H_
#include "matrix.h"
#include "dataset.h"
#include <vector>

// void runTask1(const string ifilename, const string ofilename, const string nfilename, int n, int k);
// double cosineSimilarity(vector<double> r1, vector<double> r2);
// double kmeansClustering(int k);

class Task1 
{
    public:
    void executeTask1(const string ifilename, const string ofilename, const string nfilename, int n, int k);
    double cosineSimilarity(vector<double> r1, vector<double> r2);
    double kmeansClustering(int k);

};

#endif