#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void InsertionSort(vector<int>& arr, int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
            count++;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort Step Count : " << count << endl;
}

int main() {
    fstream file;
    file.open("out.txt");
    if (!file) {
        cerr << "Error: File not found!" << endl;
        return 1;
    }

    int n = 15000;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        if (!(file >> arr[i]))
            break;
    }
    cout<<"Amount of Data : "<<n<<endl;
    clock_t start1 = clock();
    InsertionSort(arr, n);
    clock_t end1 = clock();

    cout << "Time to calculate Insertion Sort : " << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
}
