#include "task1.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
void runTask1(const string ifilename, const string mofilename, const string nfilename, int n, int k)
{
    DataSet data;
    data.read_from_csv(ifilename, n);

    Matrix mdata(data.no_of_records(),data.get_data_set()[0].get_record().size());
    // mdata.re_size(data.no_of_records(),data.get_data_set()[0].get_record().size());
    mdata.convert_from_dataset(data);
    vector< vector<double> > matrix = mdata.get_matrix();

    cout<<"lol"<<endl;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"lol"<<endl;

    Matrix cosim(data.no_of_records(), data.no_of_records());
    cosim.re_size(data.no_of_records(), data.no_of_records());
    // vector< vector<double> > cosinesim = cosim.get_matrix();

    int size = data.no_of_records();
    
    // vector<double> temp;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cosim.set_value(i,j,(cosineSimilarity(matrix[i], matrix[j])));
        }
    }

    cosim.output_to_csv(mofilename);

    //To Do: K cluster Algorithm

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cosim.set_value(i,j,1-cosim.get_value(i,j));
        }
    }
    //cosim is now Cosine Dissimilarity Matrix


    vector<vector<vector<double>>> clusters(k);

    int size = data.no_of_records();
    vector<vector<double>> datmat = mdata.get_matrix();
    vector<vector<double>> centroids;
    int count=k;

    vector<double> temp;
    int choice;
    set<int> kset;
    vector<int> clusterindex;

    vector<int> rowtocluster;
    while(count--)
    {
        choice = rand()%size;
        while(kset.find(choice))
        {
            choice = rand()%size;
        }
        kset.insert(choice);
        clusterindex.push_back(choice);
        clusters[clusters.size()].push_back(datmat[i]);
        centroids.push_back(datmat[i]);
    }

    for(int i=0;i<size;i++)
    {
        if(kset.find(i)) 
        {
            int index=0;
            while(index<clusterindex.size())
            {
                if(clusterindex[index]==i)
                {
                    rowtocluster.push_back(index);  //Row to Cluster value updation
                    break;
                }
                index++;
            }
            continue;
        }

        vector<double> comparision;
        //Finding the cosine dissimilarity values for each cluster 
        for(int j=0;j<k;j++)
        {
            comparision.push_back(1 - cosineSimilarity(centroid[j],datmat[i]));
        }

        //Choosing the cluster with minimum dissimilarity
        int minindex=0;
        double minvalue=9999999999.9999;
        int iter=0;
        while(iter<k)
        {
            if(comparision[iter]<minvalue)
            {
               minvalue = comparision[iter];
               minindex = iter;
            }
            iter++;
        }

        clusters[minindex].push_back(datmat[i]);

        //Updating centroid for that cluster
        for(int q=0;q<centroid[minindex].size();q++)
        {
            centroid[minindex][q] = averageFunction(clusters[minindex], q);
        }

        rowtocluster.push_back(minindex);
    }
    

    //Create new DataSet and output to file
    data.add_a_column(rowtocluster);
    data.output_to_csv(nfilename);
}

double averageFunction(vector<vector<double>> temp, int q)
{
    double sum = 0;
    for(int i=0;i<temp.size();i++)
    {
        sum+=temp[i][q];
    }
    sum/=temp.size();
}

double cosineSimilarity(vector<double> r1, vector<double> r2)
{
    double answer=0;
    for(int i=0;i<r1.size();i++)
    {
        answer+=r1[i]*r2[i];
    }

    double norm1,norm2;

    norm1 = 0.0;
    for(int i=0;i<r1.size();i++)
    {
        norm1 += r1[i]*r1[i];
    }
    norm1 = sqrt(norm1);

    norm2 = 0.0;
    for(int i=0;i<r2.size();i++)
    {
        norm2 += r2[i]*r2[i];
    }
    norm2 = sqrt(norm2);

    // cout<<answer<<"beforenorm"<<endl;

    answer/=norm1;
    answer/=norm2;

    // cout<<answer<<"afternorm"<<endl;

    return answer;
}
