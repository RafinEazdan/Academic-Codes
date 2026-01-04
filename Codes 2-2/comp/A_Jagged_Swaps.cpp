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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i = 0; i <n; i++)
        {
            /* code */
            if (a[0]==1){
                cout<<"YES\n";
                break;
        }
            else {
                cout<<"NO\n";
                break;
            }
        }
        
    }
    return 0;
}
//The sun will shine on us again.