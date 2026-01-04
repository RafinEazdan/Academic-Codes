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
        int a[n],x[n];
        vector<int>v;
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin>>a[i];
        }
        

        for (int i = 0; i < n; i++)
        {
            /* code */
            int mul=1;
            int b = a[i]+1;
            for (int j = 0; j <n; j++)
            {
                /* code */
                
                
                if(i==j){
                    mul = mul*b;
                }
                else{
                    mul = a[j]*mul;
                }
                
            }
            
            v.push_back(mul);
            
        }
        cout<<*max_element(v.begin(),v.end())<<endl;
        
    }
    return 0;
}
//The sun will shine on us again.