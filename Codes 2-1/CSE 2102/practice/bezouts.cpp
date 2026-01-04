#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct in{
    int x,y,gcd;
};

in extended(int a, int b){
    if(b==0){
        in ans;
        ans.gcd=a;
        ans.x=a;
        ans.y=0;
        return ans;
    }
    in smallans = extended(b,a%b);
    in ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y= smallans.x-(a/b)*smallans.y;
    return ans;
}


int main()
{
    int a,b;
    cin>>a>>b;
    in ans=extended(a,b);
    cout<<ans.gcd<<" x="<<ans.x<<" y="<<ans.y<<endl;
    
    return 0;
}