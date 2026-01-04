//Lab-1: Algorithm::Designing a Summation Algorithm
#include<bits/stdc++.h>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int main(){
    int count=0;
    int a[5]={5,6,7,8,9};
    int sum=0;
    count++;
    for(int i=0;i<5;i++){
        count++;
        sum=sum+a[i];
        count++;
    }
    cout<<sum;
    count++;
    cout<<endl<<"steps = "<<count<<endl;
    return 0;
}