#include <iostream>
#include <climits> // for INT_MAX and INT_MIN

void MaxMin(int i, int j, int* a, int& max, int& min);

int main() {
    // Example usage
    const int size = 5;
    int arr[size] = {3, 1, 4, 2, 5};
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    MaxMin(0, size - 1, arr, max_value, min_value);

    std::cout << "Maximum value: " << max_value << std::endl;
    std::cout << "Minimum value: " << min_value << std::endl;

    return 0;
}

void MaxMin(int i, int j, int* a, int& max, int& min) {
    if (i == j) {
        // Base case: array has only one element
        max = min = a[i];
    } 
    else if (i == j - 1) {
        // Another base case: array has two elements
        if (a[i] < a[j]) {
            max = a[j];
            min = a[i];
        } 
        else {
            max = a[i];
            min = a[j];
        }
    } 
    else {
        // Recursive case: divide the array into subproblems
        int mid = (i + j) / 2;

        // Solve the subproblems recursively
        int max1, min1;
        MaxMin(i, mid, a, max, min);
        MaxMin(mid + 1, j, a, max1, min1);

        // Combine the solutions
        if (max < max1) max = max1;
        if (min > min1) min = min1;
    }
}