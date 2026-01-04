#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int p[100];

int JS(int d[],int j[], int n)
{
    for (int i = 1; i <=n; i++)
    {
       for (int j = 1; j <=n; j++)
       {
         if (p[j]<p[j+1])
         {
            swap(p[j], p[j+1]);
            swap(d[j],d[j+1]);
         }

       }

    }
    d[0]=j[0]=0;
    j[1] = 1;
    int k = 1 ;
    for (int i = 2; i <=n; i++)
    {
        int r = k;
        while (d[j[r]]>d[i] && d[j[r]]!=r)
        {
            r = r-1;
        }
        if (d[j[r]]<=d[i] && d[i]>r)
        {
            for (int q = k; q >= r+1; q--)
            {
                j[q+1] = j[q];
            }
            j[r+1] = i;
            k = k+1;

        }
    }
    return k;

};
int main()
{
    ifstream inputFile("jobsequence.txt");
    int n;
    int d[100], j[100];
    inputFile>>n;

    for (int i = 1; i <=n; i++)
    {
        inputFile>>p[i]>>d[i];
    }
    int k = JS(d,j,n);

    for (int i = 1; i <=k; i++)
    {
        cout<<"Job "<<j[i]<<"\n";
    }
    inputFile.close();

    return 0;
}
