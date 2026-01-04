#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;



int main(){
    vector<pair<ll,ll>>p;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    int trianglePossible  = (n*(n-1)*(n-2))/6;
    cout<<trianglePossible;

    return 0;
}
//The sun will shine on us again.