#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#define ll long long
#define ld long double

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];
        // int data;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < q; i++)
        {
            /* code */
            int q[n];
            copy(a,a+n,q);
            
            int l, r, k;
            cin >> l >> r >> k;
            for (int j = l-1; j < r; j++)
            {
                q[j] = k;
            }
            int sum = 0;
            for (int x = 0; x < n; x++)
            {
                /* code */
                sum = sum + q[x];
                // cout<<a[x]<<" ";
            }
            // cout<<endl<<"sum = "<<sum<<endl;
            if (sum % 2 != 0)
                cout << "YES\n";
            else
                cout << "NO\n";
            
        }
    }
    return 0;
}
// The sun will shine on us again.