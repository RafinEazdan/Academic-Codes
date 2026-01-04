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
        int n,x;
        cin>>n>>x;

        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            for(int i=0;i<n;i++){
            cout<<a[i]<<endl;
        }
        }
        else if(n==0){
            cout<<2*x<<endl;
        }
        else{
            
            // for(int i=0;i<=x;i++){
            //     b[i]=i;
            // }
            for(int i=0;i<n-1;i++){
            b[i] = a[i]-a[i+1];
        }
        int &m = *min_element(b,b+n-1);
        // cout<<"Minimum of B  "<<m<<"for test="<<t<<endl;
        int ans = x+m;
        cout<<ans<<endl;
        }
    }
    return 0;
}
//The sun will shine on us again.