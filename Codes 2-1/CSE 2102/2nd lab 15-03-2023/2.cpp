#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cout<<"Input number:";
    cin>>n;
    int x=0;
    while(1){
        if(n%2==0){
            x=n/2;
            if(x==1){
                cout<<"YES! It reaches to 1";
                break;
            }
            else if(x==0){
                cout<<"It does not reaches to 1";
                break;
            }
            else{
                n=x;
            }
        }
        else{
            x=3*n+1;
            if(x==1){
                cout<<"YES! It reaches to 1";
                break;
            }
            else if(x==0){
                cout<<"It does not reaches to 1";
                break;
            }
            else{
                n=x;
            }
        }
    }

	return 0;
}

//The sun will shine on us again