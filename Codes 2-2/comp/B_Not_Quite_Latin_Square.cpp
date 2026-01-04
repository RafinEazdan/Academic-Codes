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
    char a[3][3];
    int fa=0,fb=0,fc=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            /* code */
            cin>>a[i][j];
            if (a[i][j]=='A')
                fa++;
            else if(a[i][j]=='B')
                fb++;
            else if(a[i][j]=='C')
                fc++;
        }
        
    }
    if(fa!=3) cout<<"A\n";
    else if(fb!=3) cout<<"B\n";
    else if(fc != 3) cout<<"C\n";
    
    
    }
    return 0;
}
//The sun will shine on us again.