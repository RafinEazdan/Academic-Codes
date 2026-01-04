#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int diff (int n){
    int i=1;
    while(i<=n){
        i=i*2;
    }
    return (n-(i/2));
}
int main(){
    int n;
    cin>>n;
    int c;
    while(n != 0){
        n = diff(n);
        c++;
    }
    cout<<c<<endl;
    return 0;
}
//The sun will shine on us again.