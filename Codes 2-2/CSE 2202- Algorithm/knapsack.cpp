#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void knapsack(int n, double weights[], double profits[], double capacity) {
    double resultVector[20], totalProfit = 0;
    int i;
    double remainingCapacity = capacity;

    for (i = 0; i < n; i++)
        resultVector[i] = 0.0;

    for (i = 0; i < n; i++) {
        if (weights[i] > remainingCapacity)
            break;
        else {
            resultVector[i] = 1.0;
            totalProfit += profits[i];
            remainingCapacity -= weights[i];
        }
    }

    if (i < n)
        resultVector[i] = remainingCapacity / weights[i];

    totalProfit += resultVector[i] * profits[i];

    cout << "\nThe result vector is: ";
    for (i = 0; i < n; i++)
        cout << resultVector[i] << "\t";

    cout << "\nMaximum profit is: " << totalProfit << endl;
}

int main() {
    ifstream inputFile("knapsack.txt");
    int n = 100;
    double weights[n + 5], profits[n + 5], knapsackCapacity;
    int num, i, j;
    double ratios[n + 5], temp;

    inputFile >> num;

    for (i = 0; i < num; i++) {
        inputFile >> weights[i];
    }

    for (i = 0; i < num; i++) {
        inputFile >> profits[i];
    }

    cout << "\nEnter the capacity of knapsack:- ";
    cin >> knapsackCapacity;
    cout<< "Ratios";

    for (i = 0; i < num; i++) {
        ratios[i] = profits[i] / weights[i];
        cout<<" \t"<<ratios[i];
    }

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratios[i] < ratios[j]) {
                temp = ratios[j];
                ratios[j] = ratios[i];
                ratios[i] = temp;

                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;

                temp = profits[j];
                profits[j] = profits[i];
                profits[i] = temp;
            }
        }
   }

    knapsack(num, weights, profits, knapsackCapacity);
    inputFile.close();

}
