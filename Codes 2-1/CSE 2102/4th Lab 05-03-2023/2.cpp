#include <iostream>
//#include <bits/stdc++.h>
#include<cmath>

using namespace std;

int main (){
    int u,l,a,r,j,p;
    int sum=0;
    cout<<"Input Upper Limit:";
    cin>>u;
    cout<<"Input Lower Limit:";
    cin>>l;
    cout<<"Input first variable:";
    cin>>a;
    cout<<"Input second variable:";
    cin>>r;
    for(int i=l;i<=u;i++){
        p=pow(r,i);
        sum=a*p+sum;
    }
    cout<<sum<<endl;
	return 0;
}

//The sun will shine on us again