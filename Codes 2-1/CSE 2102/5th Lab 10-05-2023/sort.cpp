#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
#define ld long double

using namespace std;

int step=0,step2=0;

void merge(int arr[],int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        step2++;
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
            k++;
            i++;
    }
    while(j<n2){
        arr[k]=b[j];
            k++;
            j++;
    }

}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int part(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for (int j=l;j<r;j++){
        step++;
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
        
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    ofstream file;
    file.open("sort.txt");
    int data, n;
    while(1){
    cout <<endl<<endl<< "How many numbers to generate: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        data = rand();

        file << data << endl;
        a[i] = data;
    }
    cout << "What type of Sort you want to perform:\n 1.Quick Sort\n 2.Merge Sort\n 3.Exit the Program\n";
    int choice;
    cin>>choice;
    if(choice==1){
        clock_t quick;
    ofstream sortedFile;
    sortedFile.open("QuickSorted.txt");
    quick = clock();
    sortedFile<<"Quick Sorted:\n";
    quickSort(a,0,n-1);
    quick = clock() - quick;
    for(int i=0;i<n;i++){
        sortedFile<<a[i]<<endl;
    }
    cout<<"QuickSort time= "<<quick<<endl;
    sortedFile.close();
    step=0;
    }
    else if(choice == 2){
        ofstream mergefile;
        mergefile.open("mergeSort.txt");
        mergefile<<"Merge sorted:\n";
        mergeSort(a,0,n-1);
        for(int i=0;i<n;i++){
        mergefile<<a[i]<<endl;
        }
        cout<<endl<<"MargeSort steps= "<<step2<<endl;
        mergefile.close();
        step2=0;
    }
    else if(choice==3){
        cout<<"Program Terminated!\n";
        exit(0);
    }
    else{
        cout<<"Invalid Input\n";
    }
    file.close();
    
    }
    return 0;
}