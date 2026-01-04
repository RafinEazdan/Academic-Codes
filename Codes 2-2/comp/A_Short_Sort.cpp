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
        string a;
        cin>>a;
        if(a[0]=='b' && a[1]=='c') 
        {
            cout<<"NO"<<endl;
        }
        else if(a[0]=='c' && a[1]=='a') {
            cout<<"NO"<<endl;
        }
        // else if(a[0]=='c' && a[1]=='b') 
        // {
        //     cout<<"NO\n"<<endl;
        // }
        else{
            cout<<"YES\n";
        }

    }
    
    return 0;
}
//The sun will shine on us again.