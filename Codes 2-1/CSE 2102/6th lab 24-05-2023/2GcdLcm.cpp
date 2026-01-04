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

int compare(map<int,int>a,map<int,int>b){
    int asize=a.size();
    int bsize=b.size();
    for(auto v:a){

    }
}

int main (){
    int n,m;
    cout<<"Input 1st number: ";
    cin>>n;
    cout<<"Input 2nd number: ";
    cin>>m;
    map<int,int>a,b;
    primeFactor(n);
    a=primeFactor(n);
    primeFactor(m);
    b=primeFactor(m);
    compare(a,b);
    int an[100],am[100];
    
    cout<<endl;
	return 0;
}

//The sun will shine on us again