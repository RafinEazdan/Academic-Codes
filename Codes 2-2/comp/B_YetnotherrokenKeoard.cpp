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
        string a;
        cin>>a;
        // a.erase(a.begin()+2);
        for (int i = 0; i < a.size(); i++)
        {
            /* code */
            if(a[i]=='B'){
                for (int j = i; j >= 0; j--)
                {
                    /* code */
                    if(a[j]>='A' && a[j]<='Z'){
                        a.erase(a.end()-j);
                        // a.erase(a.begin()+i);
                        break;
                    }
                }
                a.erase(a.begin()+i-1);
                
            }
        }
        
        cout<<a;

    }
    return 0;
}
//The sun will shine on us again.