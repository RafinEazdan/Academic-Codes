#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(vector<int>& arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
                count++;
            }
        }
    }
    cout << "Selection Sort Step count : " << count << endl;
}

int main() {
    fstream file;
    file.open("out.txt");
    if (!file) {
        cerr << "Error: File not found!" << endl;
        return 1;
    }

    int n = 10;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        if (!(file >> arr[i]))
            break;
    }
    cout<<"Amount of Data : "<<n<<endl;
    clock_t start1 = clock();
    SelectionSort(arr, n);
    clock_t end1 = clock();

    cout << "Time to calculate Selection Sort : " << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
}
