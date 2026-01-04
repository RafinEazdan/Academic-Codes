#include<bits/stdc++.h>
#include<fstream>
#define ll long long
#define dl long double

using namespace std;
static int flag=0;
int Rsum(int a[], int n){
	flag++;
	if (n<=0){
		 flag++;
		//cout<<"Steps = "<<count<<endl;
		return 0;
	}
	else{
		flag++;
		//cout<<"Steps = "<<count<<endl;
		return (Rsum(a,n-1)+a[n-1]);
	}
}

int main(){
	int n=5;
	int a[n]={5,6,7,8,9};
	Rsum(a,n);
	cout<<flag<<endl;
	return 0;
}