#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define ld long double

using namespace std;

void lin_Srch(int a[], int n)
{

    int stepLn = 0;
    int sL, flag = 0, key;
    cout << "The value you want to Linearly search =";
    cin >> sL;
    for (int i = 0; i < n; i++)
    {
        stepLn++;
        if (sL == a[i])
        {

            flag = 1;

            key = i;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        cout << "\n"
             << "Key:" << key << "\t"
             << "Value:" << sL << "\tTotal Steps:" << stepLn << endl;
    }
    else if (flag == 0)
    {
        cout << "\n"
             << "Key:Not found"
             << "\t"
             << "Value:Data Not Found!"
             << "\tTotal Steps:" << stepLn << endl;
    }
}
void bin_Srch(int a[], int n)
{
    int stepbn = 0, flag = 0, key1;
    sort(a, a + n);
    int low = 0;
    int high = n - 1;
    cout << "The value you want to Binary Search:";
    int x;
    cin >> x;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        stepbn++;
        if (a[mid] == x)
        {
            key1 = mid;

            break;
        }
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << "\n"
         << "Key:" << key1 << "\t"
         << "Value:" << x << "\tTotal Steps:" << stepbn << endl;
}
int main()
{
    ofstream file;
    file.open("random.txt");
    int data, n;
    cout << "How many numbers to generate: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        data = rand();

        file << data << endl;
        a[i] = data;
    }
    while (1)
    {
        cout << "What type of Search you want to perform:\n 1.Linear Search\n 2.Binary Search\n 3.Exit the Program\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            clock_t startl = clock();
            lin_Srch(a, n);
            clock_t end = clock();
            cout<<"\n Linear Search Time= "<<(float)(end-startl)/CLOCKS_PER_SEC<<endl;
        }
        else if (choice == 2)
        {
            clock_t startb = clock();
            bin_Srch(a, n);
            clock_t endb = clock();
            cout<<"\n binary Time = "<<(float)(endb-startb)/CLOCKS_PER_SEC<<endl;
        }
        else if (choice == 3)
        {
            cout << "Program Ended!\n";
            exit(0);
        }
        else
        {
            cout << "INVALID CHOICE INPUT\n";
        }
    }
    file.close();
    return 0;
}