#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>=10) cout<<"YES\n";
        else if(b+c>=10) cout<<"YES\n";
        else if(c+a>=10)cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
//The sun will shine on us again.