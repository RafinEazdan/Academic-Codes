#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,m;
    cin>>n>>p>>m;
    int a=m-1;
    int k=p%(m-1);
    int l = pow(n,k);
    int f=l%m;
    cout<<f<<endl;
    return 0;
}