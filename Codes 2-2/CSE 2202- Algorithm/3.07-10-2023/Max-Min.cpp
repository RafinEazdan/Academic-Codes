#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define ld long double

using namespace std;

int step1, step2;

void straightMaxMin(int a[], ll n)
{
    int maxS, minS;
    maxS = a[0];
    minS = a[0];
    for (int i = 1; i < n; i++)
    {
        step1++;
        if (a[i] > maxS)
        {
            maxS = a[i];
        }
        if (a[i] < minS)
        {
            minS = a[i];
        }
    }
    cout << "Straight Max-Min:\nMax=" << maxS << "\tMin=" << minS << endl;
}

void MaxMin(int i, int j, int *a, int &max, int &min)
{
    
    if (i == j)
    {
        max = min = a[i];
    }
    else if (i == j - 1)
    {
        
        if (a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            max = a[i];
            min = a[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, min1;
        MaxMin(i, mid, a, max, min);
        MaxMin(mid + 1, j, a, max1, min1);
        step2++;
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main()
{
    ofstream file;
    file.open("data.txt");
    int data, n;
    cout << "How many numbers to generate: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        data = rand();
        file << data << endl;
    }
    file.close();
    ifstream file2;
    file2.open("data.txt");
    int i = 0;
    while(!file2.eof()){
        file2 >> a[i++];
    }
    clock_t start = clock();
    straightMaxMin(a, n);
    clock_t end = clock();
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    clock_t startR = clock();
    MaxMin(0, n - 1, a, max_value, min_value);
    clock_t endR = clock();
    cout << "Divide and Conquer:\nMaximum value: " << max_value << endl;
    cout << "Minimum value: " << min_value << endl;
    cout << "Straight MaxMin Time =" << (float)(end - start) / CLOCKS_PER_SEC << "\nD&C MaxMin Time =" << (float)(endR - startR) / CLOCKS_PER_SEC << endl;
    return 0;    
}