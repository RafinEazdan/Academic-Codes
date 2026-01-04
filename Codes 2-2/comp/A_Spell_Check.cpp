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
        string a = "Timur";
        int n;
        cin>>n;
        string b;
        cin>>b;
        int f=0;
        if (b.size()!=5){
            cout<<"NO\n";
        }
        else{
            for (int i = 0; i < 5; i++)
            {
                /* code */
                if(b[0]==a[i]) f++;
                else if(b[1]==a[i]) f++;
                else if(b[2]==a[i]) f++;
                else if(b[3]==a[i]) f++;
                else if(b[4]==a[i]) f++;
            }
            // cout<<f<<endl;
            if(f!=5) cout<<"NO\n";
            else cout<<"YES\n";
        }
    
    }
    return 0;
}
//The sun will shine on us again.