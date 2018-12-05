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

void runTask5(string inputfile, string outputfile, int ev)
{
    task5 task(inputfile);
    task.power_itration(ev);
    task.output_to_csv(outputfile);
}