#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

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
    int flagx=0,flagy=0;
    for(int i=0;i<a;i++){
        bool k=false;
        int county=0;
        for(int j=0;j<b;j++){
            int m=x[i];
            int n=y[j];
            if((m*m-n)<3){
                county++;
            }
        }
        if(county>0){
            k=true;
            flagx++;
            //break;
        }
        
    }
    for(int j=0;j<b;j++){
        bool k=false;
        int countx=0;
        for(int i=0;i<a;i++){
            int m=x[i];
            int n=y[j];
            if((m*m-n)<3){
                countx++;
            }
        }
        if(countx>0){
            k=true;
            flagy++;
            //break;
        }
        
    }
    if(flagx==a && flagy>0)
    cout<<"For all x and for some y true\n";
    else{
        cout<<"For all x and for some y false\n";
    }
    cout<<endl<<flagx<<endl<<flagy<<endl;
} 