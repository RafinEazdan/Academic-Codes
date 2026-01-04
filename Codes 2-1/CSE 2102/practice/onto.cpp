#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    cout<<"domain";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Co-domain";
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    int c[m];
    int k;
    for (int i = 0; i < n; i++)
    {
        k = a[i]*a[i]*a[i]-a[i]+1;
        c[i]=k;
    }
    sort(b,b+m);
    sort(c,c+m);
    int flag=0;
    for (int i = 0; i < m; i++)
    {
        if(c[i] != b[i]){
            cout<<"Not Onto\n";
            break;
        }
        else{
            flag++;
        }
    }
    if(flag==m){
        cout<<"Onto Funtion\n";
    }
    
    
    
    return 0;
}