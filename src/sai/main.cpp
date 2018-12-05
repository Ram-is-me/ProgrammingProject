#include<iostream>
#include <vector>
#include <string>
#include "dataset.h"
#include "task5.h"
#include "matrix.h"
using namespace std;
int main()
{
    task5 task("input.csv");
    task.power_itration(3);
    task.output_to_csv("output.csv");
}