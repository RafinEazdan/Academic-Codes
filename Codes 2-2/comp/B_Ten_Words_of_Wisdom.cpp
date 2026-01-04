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
        vector<pair<int,int>>v;
        for (int i = 0; i <n; i++)
        {
            /* code */
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b)); 
        }
        int flag =0;
        vector<int>r; 
        for (auto [x,y]:v){
            if(x<=10){
                r.push_back(y);
            }
            else{
                r.push_back(0);
            }
        }
        // cout<<endl;
        // for(auto i: r){
        //     cout<<i<<" ";
        // }cout<<endl;
        auto it = max_element(r.begin(),r.end());
        if(it != r.end()){
            
            int index = distance(r.begin(),it)+1;
            cout<<index<<endl;
        }
        // r.clear();
        // v.clear();
        
    }
    return 0;
}
//The sun will shine on us again.