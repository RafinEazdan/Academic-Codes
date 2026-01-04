#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<pair<ll, ll>> store;
static bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    double a_angle = (double)(a.second - store[1].second) / (double)(a.first - store[1].first);
    double b_angle = (double)(b.second - store[1].second) / (double)(b.first - store[1].first);
    return a_angle < b_angle;
}
ll ccw(ll a, ll b, ll c)
{
    return (store[b].first - store[a].first) * (store[c].second - store[a].second) - (store[b].second - store[a].second) * (store[c].first - store[a].first);
}
int main()
{
    ll n;
    cin >> n;
    store.push_back({0, 0});
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        store.push_back({x, y});
    }
    for (ll i = 2; i <= n; i++)
    {
        if (store[1].second > store[i].second)
        {
            swap(store[1].second, store[i].second);
            swap(store[1].first, store[i].first);
        }
    }
    sort(store.begin() + 2, store.end(), cmp);
    store[0].first = store[n].first;
    store[0].second = store[n].second;

    ll M = 1;
    for (ll i = 2; i <= n; i++)
    {
        while (ccw(M - 1, M, i) <= 0)
        {
            if (M > 1)
                M--;
            else if (i == n)
                break;
            else
                i++;
        }
        M++;
        swap(store[M].first, store[i].first);
        swap(store[M].second, store[i].second);
    }
    for (ll i = 0; i < M; i++)
    {
        cout << store[i].first << " " << store[i].second << endl;
    }
}