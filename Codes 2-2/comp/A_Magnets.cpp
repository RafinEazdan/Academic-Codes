#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        v.push_back(data);
    }
    vector<int>f;
    int flag=1;
    for(int i=0;i<n-1;i++){
        //cout<<i<<endl;
        if(v[i] != v[i+1]){
            flag++;
            // cout<<"If flag = "<<flag<<endl;
             
        }
        
    }
    // cout<<endl;
    // for(auto k:f){
    //     cout<<k<<" ";
    // }cout<<endl;
    cout<<flag<<endl;

    return 0;
}
//The sun will shine on us again.