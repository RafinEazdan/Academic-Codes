#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    if(n%100 == 0 || n%1000==0 || n%10000==0){
        cout<<"1\n"<<n<<endl;
    }
    else if((n>=1 && n<=10) || n==0){
        cout<<"1\n"<<n<<endl;
        
    }
    else if(n>10 && n<100){
        int a = n%10;
        int b = n-a;
        cout<<"2\n"<<b<<" "<<a<<endl;
    }
    else if(n>100 && n<1000){
        int a = n%100;
        int b = n-a;
        int c = a%10;
        int d = a-c;
        cout<<"3\n"<<b<<" "<<c<<" "<<d<<endl;
    }
    else if(n>1000 && n<10000){
        int a = n%1000;
        int b = n-a;
        int c = a%100;
        int d = a-c;
        int e = c%10;
        int f = c-e;
        cout<<"4\n"<<b<<" "<<d<<" "<<e<<" "<<f<<endl;
    }
    
    }
    return 0;
}
//The sun will shine on us again.