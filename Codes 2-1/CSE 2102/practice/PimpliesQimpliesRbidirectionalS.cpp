#include<iostream>
#include<algorithm>
using namespace std;

bool AimpliesB(bool a, bool b){
    if(a==1 && b==0){
        return 0;
    }
    else{
        return 1;
    }
    
}
bool AandB(bool a, bool b){
    if(a==1 && b==1)
        return 1;
    else{
        return 0;
    }
}

int main()
{
    cout<<"P Q R S P->Q->(R<->S))\n";
    for(int p=0;p<2;p++){
        for(int q=0;q<2;q++){
            for(int r=0;r<2;r++){
                for(int s=0;s<2;s++){
                int a=AimpliesB(r,s);
                int b = AimpliesB(s,r);
                int c=AandB(a,b);
                int d = AimpliesB(q,c);
                int e = AimpliesB(p,d);
                cout<<p<<" "<<q<<" "<<r<<" "<<s<<"     "<<e<<endl;
                }
            }
        }
    }
    return 0;
}