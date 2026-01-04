#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int step=0;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int part(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for (int j=l;j<r;j++){
        if(arr[j]<pivot){
        i++;
        swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[],int l,int r){

    if(l<r){
        int pi = part(arr,l,r);
        step++;
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    ofstream file;
    file.open("sort.txt");
    int data, n;
    cout << "How many numbers to generate: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        data = rand();
        file << data << endl;
    }
    file.close();
    ifstream file2;
    file2.open("sort.txt");
    int i = 0;
    while(!file2.eof()){
        file2 >> a[i++];
    }
    while(1){
    cout << "What type of Sort you want to perform:\n 1.Quick Sort\n 2.Merge Sort\n 3.Exit the Program\n";
    int choice;
    cin>>choice;
    if(choice==1){
    ofstream sortedFile;
    sortedFile.open("Sorted.txt");
    
    sortedFile<<"Quick Sorted:\n";
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        sortedFile<<a[i]<<endl;
    }
    cout<<endl<<"QuickSort steps= "<<step<<endl;
    sortedFile.close();
    }
    else if(choice == 2){
        ofstream mergefile;
        mergefile.open("mergeSort.txt");
        mergefile<<"Merge sorted:\n";
        
    }
    }
    file2.close();
    return 0;
    }
