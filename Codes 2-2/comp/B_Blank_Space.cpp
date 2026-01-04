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
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        
        cin>>v[i];
        
    }
    int c = 0,t=0;
    for(int i=0;i<n;i++){
       if(v[i]==0){
        c++;
        t = max(t,c);
       } 
       else{
        c=0;
       }
        
    }
    // if(t>1)
    cout <<t<<endl;
    // else cout<<"0\n";

    
    
    }
    return 0;
}
//The sun will shine on us again.