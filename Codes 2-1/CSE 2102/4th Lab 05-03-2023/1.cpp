#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main (){
    int u,l,a,n,d;
    int sum=0;
    cout<<"Input Upper Limit:";
    cin>>u;
    cout<<"Input Lower Limit:";
    cin>>l;
    cout<<"Input first variable:";
    cin>>a;
    cout<<"Input second variable:";
    cin>>d;
    for(int i=l;i<=u;i++){
        sum=a+i*d+sum;
    }
    cout<<sum;
	return 0;
}

//The sun will shine on us again