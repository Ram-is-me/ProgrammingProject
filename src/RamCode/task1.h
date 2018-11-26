#ifndef TASK1_H
#define TASK1_H
#include "symmetricmatrix.h"
#include <vector>
class Task1 
{
    public:
    static void runTask1();
    private:
    static double cosineSimilarity(vector<double> r1, vector<double> r2);
    static double kmeansClustering(int k);
};

#endif