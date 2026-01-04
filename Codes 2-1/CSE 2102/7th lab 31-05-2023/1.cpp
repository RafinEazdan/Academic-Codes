#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;


int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 1;
        y = 0;
        return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
 
    return gcd;
}

int main (){
    int n;
    cout<<"How many funtions to input:";
    cin>>n;
    cout<<"Input functions:";
    vector<int>a(n),m(n);
    for(int i=0;i<n;i++){
        cout<<"\nx=";
        cin>>a[i];
        cout<<"(mod)";
        cin>>m[i];
    }
    int mn= m.size();
    int M=1;
    for(int i=0;i<n;i++){
        M=m[i]*M;
    }
    vector<int>Mi(n);
    for(int i=0;i<n;i++){
        Mi[i]=M/m[i];
    }
    
    vector<int>xa(n),ya(n),result(n);
    int x,y;
    for(int i=0;i<n;i++){
        
        gcdExtended(m[i],Mi[i],x,y);
        cout<<"x="<<x<<endl;
        if(x<0){
            x=x*(-1);
        }
        result[i]=x*a[i]*Mi[i];
        
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=result[i]+sum;
    }
    int summod=sum%M;
    cout<<"Answer:    "<< summod <<" mod "<<M;

	return 0;
}

//The sun will shine on us again