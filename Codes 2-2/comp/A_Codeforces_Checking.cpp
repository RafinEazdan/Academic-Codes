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
    string a = "codeforces";
    char s;
    cin>>s;
    int f=0;
    for (int i = 0; i < a.size(); i++)
    {
        /* code */
        if(s==a[i])
         f++;
    }
    if(f>0) cout<<"YES\n";
    else cout<<"NO\n";
    
    
    }
    return 0;
}
//The sun will shine on us again.