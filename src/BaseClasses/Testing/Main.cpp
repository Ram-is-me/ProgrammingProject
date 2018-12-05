#include "symmetricmatrix.h"
#include "dataset.h"
#include "task1.h"
#include "task5.h"
#include <iostream>

// void runTask4(string inputFile, string outputFile1);
void runTask5(string inputFile, string outputFile1, int ev);
// void runTask6(string inputFile, string outputFile1);
// void runTask7(string inputFile, string outputFile1);
// void runTask8(string inputFile, string outputFile1);

int main()
{
    cout<<"Welcome to a Simple Tabular Data Processing toolkit\n";
    cout<<"We support a total of 6 functionalities.\n";
    cout<<"Please refer to the README for more details\n";
    cout<<"Please Enter a Number (1-6) to run the corresponding Task\n";
    cout<<"1 4 5 6 7 8 -- 1 2 3 4 5 6\n";
    cout<<"Press 0 to Quit\n";
    int choice;
    cin>>choice;
    string inputFile, outputFile1, outputFile2;
    while(choice)
    {
        switch(choice)
        {
            case 1:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File 1 Name\n";
                cin>>outputFile1;
                cout<<"Provide Output File 2 Name\n";
                cin>>outputFile2;
                int n;
                cout<<"Provide number of Columns with Non-Numeric Values:\n";
                cin>>n;
                int k;
                cout<<"Provide number of partitions to be made:\n";
                cin>>k;
                runTask1(inputFile, outputFile1, outputFile2, n, k);
            } break;
            case 2:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask4(inputFile, outputFile1);
            } break;
            case 3:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                cout<<"Provide the Number of Eigen Vectors:\n";
                int ev;
                cin>>ev;
                runTask5(inputFile, outputFile1, ev);
            } break;
            case 4:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask6(inputFile, outputFile1);
            } break;
            case 5:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask7(inputFile, outputFile1);
            } break;
            case 6:{
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask8(inputFile, outputFile1);
            } break;
            default:
            {
                cout<<"Wrong Choice\n";
            }
        }
        cout<<"\nPlease Enter the Next Operation: [1-6] \n";
        cin>>choice;
    }

    return 0;
}

void runTask5(string inputfile, string outputfile, int ev)
{
    task5 task(inputfile);
    task.power_itration(ev);
    task.output_to_csv(outputfile);
}