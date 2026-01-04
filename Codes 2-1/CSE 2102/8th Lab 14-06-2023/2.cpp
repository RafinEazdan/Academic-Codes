#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;

int main (){
    int n;
    cout<<"Input size of set:";
    cin>>n;
    int a[n];
    cout<<"Input set values:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    int m;
    cout<<"Input size of R:";
    cin>>m;
    int b[m];
    cout<<"Input R:";
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int temp1,temp2,tempi,tempj;
    for(int i=n-1,j=m-1;i>=0,j>=0;i--,j--){
        
            if(a[i]==b[j]){
                continue;
            }
            else if(a[i]>b[j]){
                tempi=i;
                tempj=j;
                temp1=a[i];
                temp2=b[j];
                break;
            }
    }
    for(int i=0;i<n;i++){
        if(a[i]==temp1){
            
        }
    }

    


	return 0;
}

//The sun will shine on us again