#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        
        cin>>a[i];
        sum+=a[i];
        
    }
    sum=sum/2;
    int flag=0;
    int ans=0;
    sort(a,a+n);
    for (int i = n-1; i >= 0; i--)
    {
        ans+=a[i];
        flag++;
        if(ans>sum)
        break;

    }
    cout<<flag<<endl;
    


    
    return 0;
}
//The sun will shine on us again.