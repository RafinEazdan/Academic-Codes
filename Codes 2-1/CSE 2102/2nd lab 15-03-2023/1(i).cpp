#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){
    int a,b;
    cout<<"Input domain element number for X:";
    cin>>a;
    int x[a];
    cout<<"Input domain elements for X: ";
    for(int i=0;i<a;i++){
        cin>>x[i];
    } 
    cout<<"Input domain element number for Y:";
    cin>>b;
    int y[b];
    cout<<"Input domain elements for Y: ";
    for(int i=0;i<b;i++){
        cin>>y[i];
    } 
    int flagx,flagy;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int m=x[i];
            int n=y[j];
            if((m*m-n)<3){
                flagx++;
                flagy++;
            }

        }
    }
    cout<<flagx<<endl<<flagy;
	return 0;
}

//The sun will shine on us again