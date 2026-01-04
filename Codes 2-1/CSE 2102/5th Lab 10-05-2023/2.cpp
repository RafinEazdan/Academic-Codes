#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<algorithm>
#include<cmath>
#include<fstream>
#define ll long long
#define dl long double

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main (){
    fstream f;
    f.open("out.txt");
    int n;
    cout<<"Input size of Data:";
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++){
        f>>data[i];
    }
    
    clock_t start1=clock();
    bubbleSort(data,n);
    clock_t end1=clock();
    cout<<(float)(end1-start1)/CLOCKS_PER_SEC;
	return 0;
}

//The sun will shine on us again