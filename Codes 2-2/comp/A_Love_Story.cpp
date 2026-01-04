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
        string a = "codeforces";
        string b;
        cin>>b;
        int flag = 0;
        for (int i = 0; i < 10; i++)
        {
            /* code */
            if(a[i]!=b[i]) flag++;
        }
        cout<<flag<<endl;
        
        
    }
    
    return 0;
}
//The sun will shine on us again.
