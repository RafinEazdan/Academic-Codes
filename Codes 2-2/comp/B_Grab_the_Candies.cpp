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
    int a[n];
    int sumM=0;
    int sumA=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]%2==0){
            sumM=sumM+a[i];
        }
        else{
            sumA=sumA+a[i];
        }
    }
    if(sumM>sumA) cout<<"YES\n";
    else cout<<"NO\n";
    
    
    
    }
    return 0;
}
//The sun will shine on us again.