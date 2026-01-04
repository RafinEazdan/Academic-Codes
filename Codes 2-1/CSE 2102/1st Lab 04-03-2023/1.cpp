#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool notP(bool a){
    if(a== 0){
        return 1;
    }
    else{
        return 0;
    }

}
bool pimpliesq(bool p,bool q){
    if(p==0 && q==0){
        return 1;
    }
    else if(p==0 && q==1){
        return 1;
    }
    else if(p==1 && q==0){
        return 0;
    }
    else if(p==1 && q==1){
        return 1;
    }
}
bool aORb(bool a,bool b){
    if(a==0 || b==1){
        return 1;
    }
    else if(a==1 || b==0){
        return 1;
    }
    else if(a==0 || b==0){
        return 0;
    }
    else if(a==1||b==1){
        return 1;
    }
}


int main (){
    bool p,q;
    
   /* cout<<"P\tQ\t!P^(P->Q)\tP||(!q->p)\n";
    for(int i=1;i<=4;i++){
        cin>>p>>q;
        bool a=notP(p);
        bool b=pimpliesq(p,q);
        bool c=a+b;
        bool d=notP(q);
        bool e=pimpliesq(d,p);
        bool f=d||e;
        cout<<p<<"\t"<<q<<"\t"<<c<<"\t\t"<<f<<"\n";
*/
        bool a,b,c,d,e,f;
        cout<<"P\tQ\tresult1\tresult2\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                
                a=notP(i);
                b=pimpliesq(i,j);
                c=a*b;
                d=notP(j);
                e=pimpliesq(d,i);
                f=aORb(e,i);
                cout<<i<<"\t"<<j<<"\t"<<c<<"\t"<<e<<endl;

            }
           // cout<<endl;
        }
       
        
    

	return 0;
}

// The sun will shine on us again 62+530005 