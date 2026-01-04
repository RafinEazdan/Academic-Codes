#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#define ll long long
#define dl long double

using namespace std;

string swap(string a, int n, int m){
    if((n>=0 && n<a.length()) && (m>=0 && m<a.length())){
        char temp = a[n];
        a[n]=a[m];
        a[m]=temp;
    }
    return a;
}

int main(){
    string a;
    cin>>a;
    int n = a.size();
    string b;
    b=a;
    reverse(b.begin(), b.end());
    if(is_sorted(b.begin(),b.end())){
        cout<<"Next Permutayion is not possible\n";
        // return 0;
    }
    else{
        int temp1,temp2,temp1j,temp2j;
        for(int i=n-1;i>=0;i--){
            if(a[i-1]<a[i]){
                temp1=a[i-1];
                temp1j=i-1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(temp1<a[i]){
                temp2=a[i];
                temp2j=i;
                break;
            }
        }

        string a1 = swap(a,temp1j,temp2j);
        cout<<"a1="<<a1<<endl;
        string a2 = a1.substr(0,temp1j+1);
        string a3 = a1.substr(temp1j+1,n-1);
        sort(a3.begin(),a3.end());

        cout<<a2+a3<<endl;
    }
    
	return 0;
}