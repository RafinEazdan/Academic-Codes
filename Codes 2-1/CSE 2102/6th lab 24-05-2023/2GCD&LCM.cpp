#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;

int primeFactor(int n){
    while(n%2==0){
        cout<<"2 ";
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2){
        cout<<n<<" ";
    }
}

int main (){
    int n;
    cout<<"Input number: ";
    cin>>n;
    primeFactor(n);
    cout<<endl;
	return 0;
}

//The sun will shine on us again