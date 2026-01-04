#include <bits/stdc++.h>
#define ll long long
#define dl long double

using namespace std;


string swapit(string a,int first1,int second2){
    if((first1>=0 && first1<a.length()) &&(second2>=0 && second2<a.length())){
        char temp = a[first1];
        a[first1]=a[second2];
        a[second2]=temp;

    }
    return a;


}

int main (){
    string a;
    cin>>a;
    int k=a.size();
    string b=a;
    reverse(b.begin(),b.end());
    cout<<"b="<<b<<endl;
    if(is_sorted(b.begin(),b.end())){
        cout<<"Next Permutation is not possible\n";
        return 0;
    }
    else{
    int temp1,temp2,temp1j,temp2j;
    for(int j=k-1;j>=0;j--){
        if(a[j-1]<a[j]){
            temp1=a[j-1];
            temp1j=j-1;
            break;
        }
    }
    for(int j=k-1;j>=0;j--){
        if(temp1<a[j]){
            temp2=a[j];
            temp2j=j;
            break;
        }
    }
    string a1= swapit(a,temp1j,temp2j);
    cout<<"a1="<<a1<<endl;
    string a3= a1.substr(0,temp1j+1);
    cout<<"a3="<<a3<<endl;
    string a2= a1.substr(temp1j+1,k-1);
    cout<<"a2="<<a2<<endl;
    sort(a2.begin(),a2.end());
    
    cout<<a3+a2;
    return 0;
    }
	
}

//The sun will shine on us again