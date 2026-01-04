#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    ofstream file;
    file.open("knapsack.txt");
    int n;
    cin>>n;
    file<<n;
    file<<endl;
    int data,benefit;
    for(int i=0;i<n;i++){
        cin>>data;
        file<<data<<" ";
    }
    file<<endl;
    for(int i=0;i<n;i++){
        cin>>benefit;
        file<<benefit<<" ";
    }
    file<<endl;
    file.close();
    ifstream file2;
    file2.open("knapsack.txt");
    int input[2*n+1];
    for(int i=0;i<!file2.eof();i++){
        file2>>input[i];
    }
    int size;
    double w[n],b[n];
    for(int i=0;i<n;i++){
        size = input[0];
        w[i]=input[i+1];
        b[i]=input[i+n+1];
    }
    int max =20;
    double ratio[n];
    int key[n];
    for(int i=0;i<n;i++){
         ratio[i] = b[i]/(double)w[i];
         key[i]=i;
    }
    return 0;
}
//The sun will shine on us again.