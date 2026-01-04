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
    string a;
    cin>>a;
    int b[a.size()];
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = a[i] - '0';
    }
    for (int i = 0; i < a.size(); i++)
    {
        /* code */
        if(b[i]+b[i+1]+b[i+2] == b[i+3]+b[i+4]+b[i+5]){
            cout<<"YES\n";
            break;
        }
        else{
            cout<<"NO\n";
            break;
        }
    }
    
    
    
    }
    return 0;
}
//The sun will shine on us again.