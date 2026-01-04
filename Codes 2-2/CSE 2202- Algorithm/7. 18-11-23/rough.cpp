#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    ofstream file;
    file.open("rough.txt");
    int x,y;
    cout<<"How many Points to enter: ";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>x>>y;
        file<<"{"<<x<<","<<y<<"}"<<endl;
    }
    file.close();
    return 0;
}
//The sun will shine on us again.