#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int t;
    cin>>t;
    testcase:
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        for (int i = 0; i <n; i++)
        {
            /* code */
            if(a[i]=='0'){
                cout<<"YES\n";
                goto testcase;
            }
            
        }
        cout<<"NO\n";
        
    }
    return 0;
}
//The sun will shine on us again.