#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<algorithm>
#include<cmath>
#include<fstream>
#define ll long long
#define dl long double

using namespace std;

int main (){
    ofstream Myfile("out.txt");
    for(int i=0;i<200000;i++){
        Myfile<<rand()<<" ";
    }
    Myfile.close();
	return 0;
}

//The sun will shine on us again