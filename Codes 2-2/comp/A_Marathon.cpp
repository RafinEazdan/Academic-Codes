#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int f=0;
    if(a<b) f++;
    if(a<c) f++;
    if(a<d) f++;
    cout<<f<<endl;
    
    }
    return 0;
}
//The sun will shine on us again.