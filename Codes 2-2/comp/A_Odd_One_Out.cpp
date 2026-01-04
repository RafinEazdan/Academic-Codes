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
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b && a!=c)
        cout<<c<<endl;
    else if (b==c && b!=a)
        cout<<a<<endl;
    else if (c==a && c!=b)
        cout<<b<<endl;
    else
        cout<<"0\n";
    
    }
    return 0;
}
//The sun will shine on us again.