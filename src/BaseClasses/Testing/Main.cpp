#include "symmetricmatrix.h"
#include "dataset.h"
#include "task1.h"
#include "task5.h"
#include "task6.h"
#include <iostream>

void runTask1(string input, string output1, string output2, int n, int k);

// void runTask4(string inputFile, string outputFile1);
void runTask5(string inputFile, string outputFile1, int ev);
void runTask6(string input);
// void runTask7(string inputFile, string outputFile1);
// void runTask8(string inputFile, string outputFile1);

int main()
{
    cout<<"Welcome to a Simple Tabular Data Processing toolkit\n";
    cout<<"We support a total of 6 functionalities.\n";
    cout<<"Please refer to the README for more details\n";
    cout<<"Please Enter a Number (1-6) to run the corresponding Task\n";
    // cout<<"1 4 5 6 7 8 -- 1 2 3 4 5 6\n";
    cout<<"Press 0 to Quit\n";
    int choice;
    cin>>choice;
    string inputFile, outputFile1, outputFile2;
    while(choice)
    {
        switch(choice)
        {
            case 1:
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
                break;
            case 4:
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask4(inputFile, outputFile1);
                break;
            case 5:
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                cout<<"Provide the Number of Eigen Vectors:\n";
                int ev;
                cin>>ev;
                runTask5(inputFile, outputFile1, ev);
                break;
            case 6:
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<endl;
                runTask6(inputFile);
                cout<<endl;
                break;
            case 7:
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask7(inputFile, outputFile1);
                break;
            case 8:
                cout<<"Provide Input File Name:\n";
                cin>>inputFile;
                cout<<"Provide Output File Name\n";
                cin>>outputFile1;
                // runTask8(inputFile);
                break;
            default:
                cout<<"Wrong Choice\n";
        }
        cout<<"\nPlease Enter the Next Operation: [1-6] \n";
        cin>>choice;
    }

    return 0;
}

void runTask1(string input, string output1, string output2, int n, int k)
{
    Task1 t;
    t.executeTask1(input, output1, output2, n, k);
}

void runTask5(string inputfile, string outputfile, int ev)
{
    Task5 task(inputfile);
    task.power_itration(ev);
    task.output_to_csv(outputfile);
}

void runTask6(string input)
{
    Matrix m;
    m.fill_data_from_csv(input);
    min_degree_algo(m.get_matrix());
}

// void runTask7(string input)
// {
//     // Task7 t;
//     // t.reverse_cuthill_mckee(input);
//     reverse_cuthill_mckee(input);
// }