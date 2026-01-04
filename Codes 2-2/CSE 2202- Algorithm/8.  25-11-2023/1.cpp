#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;
const int inf = 1e7;
int main(){
    int n,m,source;
    ifstream file2("file2.txt");
    file2>>n>>m>>source;
    file2.close();
    vector<int>dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    ifstream file;
    file.open("file.txt");
    int u,v,w;
    while(file>>u>>v>>w){
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});//undirected graph
    }
    dist[source] = 0;
    set<pair<int,int>>s;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto i:graph[x.second]){
            if(dist[i.first]> dist[x.second] + i.second){
                s.erase({dist[i.first],i.first});//erasing old value
                dist[i.first] = dist[x.second]+i.second;//inserting new value for the condition
                s.insert({dist[i.first],i.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]<inf){
            cout<<dist[i]<<" "<<endl;
        }
        else{
            cout<<"inf "<<endl;
        }
    }
    cout<<endl;
    return 0;
}
//The sun will shine on us again.