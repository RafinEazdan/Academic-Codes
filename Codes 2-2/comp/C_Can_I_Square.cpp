#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

bool check1(ll a){
    if(a>=0){
        ld s = sqrt(a);
        if( (s*s) == a){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v[n];
        ll sum=0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin>>v[i];
            sum = sum + v[i];

        }
        // cout<<"sum = "<<sum<<endl;
        // cout<<sum<<endl;
        bool f = check1(sum);
        if (f==true) cout<<"YES\n";
        else cout<<"NO\n";
        
    
    }
    return 0;
}
//The sun will shine on us again.