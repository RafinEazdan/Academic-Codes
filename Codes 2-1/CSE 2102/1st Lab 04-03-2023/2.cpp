#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){
    int n,m;
    cout<<"Enter domain number of X: ";
    cin>>n;
     cout<<"Enter domain number of Y: ";
     cin>>m;

     int x[n],y[m];
      cout<<"Enter domain for X: ";
      for(int i=0;i<n;i++){
        cin>>x[i];
      }
       cout<<"Enter domain for Y: ";
       for(int i=0;i<m;i++){
        cin>>y[i];
       }
       int p,q,flag=0;
       for(int i=0;i<n;i++){
        p=x[i];
        for(int j=0;j<m;j++){
            q=y[j];
            if(p+q>0){
                flag++;
                break;
            }
        }
       }
       if(flag==n && flag<=m){
        cout<<"True\n";
       }
       else{
        cout<<"False\n";
       }

	return 0;
}

//The sun will shine on us again