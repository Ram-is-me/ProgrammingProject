#ifndef TASK1_H
#define TASK1_H
#include "matrix.h"
#include "dataset.h"
#include <vector>

void runTask1(const string ifilename, const string ofilename, const string nfilename, int n, int k);
double cosineSimilarity(vector<double> r1, vector<double> r2);
double kmeansClustering(int k);


#endif