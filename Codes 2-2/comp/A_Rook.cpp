#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
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
        char x,y;
        x = a[1];
        y=a[0];
        int n = x - '0';
        for (int i = 1; i <= 8; i++)
        {
            /* code */
            if(i!=n){
                cout<<y<<i<<endl;
            }
            
        }
        int flag = 1;
        for (char i = 'a'; i <='h'; i++)
        {
            /* code */
            if(i!=y){
                cout<<i<<n<<endl;
            }
        }
        
        
        
        
        
    }
    
    return 0;
}
//The sun will shine on us again.