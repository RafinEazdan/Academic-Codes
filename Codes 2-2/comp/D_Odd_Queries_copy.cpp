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
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int pref[n];
        for (int i = 1; i <= n; i++)
        {
            /* code */
            pref[i] = pref[i - 1];
            pref[i]+=a[i];
        }
        for(int i=0;i<q;i++)
        {
            int l, r, k;
            cin >> l >> r >> k;
            
            ll sum = pref[n]-(pref[r]-pref[l-1])+k*(r-l+1); 
            if (sum % 2 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        
    }
    return 0;
}
// The sun will shine on us again.