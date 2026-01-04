#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll unsigned long long
#define ld long double
#define b 100000
using namespace std;

int main(){
    ofstream file;
    file.open("file.txt");
    // srand((unsigned) time(0));
    ll v;cin>>v;
    ll d[v][v];
    for (ll i = 0; i<v; i++)
    {
        for (ll j = 0; j < v; j++)
        {
            d[i][j]=rand()% 10000+1;
            file<<d[i][j]<<" ";
        }
        // cout<<endl; 
        file<<endl;
    }
    file.close();
    return 0;
}
//The sun will shine on us again.