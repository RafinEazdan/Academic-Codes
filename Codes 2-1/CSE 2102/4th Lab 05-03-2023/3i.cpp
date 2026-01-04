#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main (){
    int m,n;
    cout<<"Input the size of the Domain:";
    cin>>m;
    cout<<"Input the size of the Co-Domain:";
    cin>>n;
   vector<int>a;
   vector<int>b;
   cout<<"Input Domain:";
   int a1,b1;
   for(int i=0 ; i<m ; i++)
    {
        cin>>a1;
        a.push_back(a1);
    }
    cout<<"Input Co-Domain:";
    for(int i=0 ; i<n ; i++)
    {
        cin>>b1;
        b.push_back(b1);
    }
    int flag=0,anti=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]*a[i]==b[j]){
                flag++;
                break;
            }
            else{
                anti++;
            }
        }
    }
    //arekta array niye array compare korte hobe::: c array niye b array er shathe compare korte hobe

    int k=b.size()-flag;
    int k1=a.size()-flag;
    if(k<=0 && k1==0 && anti<=m ){
        cout<<"This function is Onto\n";
    }
    else{
        cout<<"This function is not Onto\n";
    }
	return 0;
}

//The sun will shine on us again