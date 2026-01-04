#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;

map<int,int> primeFactor(int n){
    int a[100];
    map<int,int>mp;
    int k=0;
    while(n%2==0){
        cout<<"2 ";
        n=n/2;
        mp[2]++;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
            mp[i]++;
        }
    }
    if(n>2){
        cout<<n<<" ";
        mp.insert({k,n});
        k++;
    }
    int size= mp.size();
    int flag=0;
    for(int i=0;i<size;i++){
        if(mp[i]==mp[i+1]){
            flag++;
        }
    }
    return mp;
}


int main (){
    int b,n;
    cout<<"Input base and power:";
    cin>>b>>n;
    map<int,int>a;
    primeFactor(n);
    a=primeFactor(n);
    int nm=a.size();
    vector<pair<int,int>va;
    for(auto i:a){
        va.push_back(make_pair(i.first,i.second));
    }
    

}

//The sun will shine on us again