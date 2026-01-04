#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
  int count = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        count++;
      }
    }
  }
  cout << "Steps to count Bubble sort is : " << count << endl;
}

int main() {
  fstream file;
  file.open("out.txt");
  if (!file) {
    cerr << "Error: File not found!" << endl;
    return 1;
  }

  int n = 1000;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    if (!(file >> arr[i]))
      break;
  }
  cout<<"Amount of Data : "<<n<<endl;
  clock_t start1 = clock();
  bubbleSort(arr, n);
  clock_t end1 = clock();

  cout << "Time to calculate Bubble Sort : " << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
}
