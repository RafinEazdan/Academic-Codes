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
    //bool sec = false;
    for(int i=0;i<a;i++){
        int county=0;
        for(int j=0;j<b;j++){
            int m=x[i];
            int n=y[j];
            if((m*m-n)<3){
                flagx++;
                //flagy++;
                county++;
                
            }


        }
       // if(county>0) sec= true;
       // else sec= false;

    }
    for(int j=0;j<b;j++){
        for(int i=0;i<a;i++){
            int m=x[i];
            int n=y[j];
            if((m*m-n)<3){
                flagy++;
                //flagy++;
                
            }
            else{
                continue;
            }

        }
    }
    cout<<flagx<<endl<<flagy;
    int l=sqrt(flagx);
    int o=sqrt(flagy);

   if(l==a && o==b){
    cout<<"For all X and For all Y the value is: TRUE\n";
   }
   else{
    cout<<"For all X and For all Y the value is: FALSE\n";
   }
   if((l<a)&&(o<b)){
        cout<<"For some X and For some Y the value is: TRUE\n";

   }
   else{
        cout<<"For some X and For some Y the value is: FALSE\n";

   }
	return 0;
}

//The sun will shine on us again