#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return(gcd(b%a,a));
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main (){
    int a=10,b=15,x,y;
    gcd(a,b);
    cout<<gcdExtended(a,b,&x,&y);
	return 0;
}

//The sun will shine on us again