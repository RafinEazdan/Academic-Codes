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
    string a;
    cin>>a;
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = i; j < n; j=j+1)
        {
            if(i%2==0 && j%2!=0){
                if(a[i]==a[j]){
                    flag++;
                }

                }
            else if(i%2!=0 && j%2==0){
                if(a[i]==a[j]){
                    flag++;
                }
            }
            }
        }
        if(flag==0) cout<<"YES\n";
        else cout<<"NO\n";

        
    
    
    
    }
    return 0;
}
//The sun will shine on us again.