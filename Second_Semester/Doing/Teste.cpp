#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> prices = a;
    prices.insert(prices.end(), b.begin(), b.end());
    sort(prices.begin(), prices.end());
    prices.erase(unique(prices.begin(), prices.end()), prices.end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int max_earnings = 0;
    for (int price : prices)
    {
        int neg_reviews = upper_bound(a.begin(), a.end(), price) - a.begin();
        int total_buys = b.end() - lower_bound(b.begin(), b.end(), price);

        if (neg_reviews <= k)
        {
            max_earnings = max(max_earnings, price * total_buys);
        }
    }

    cout << max_earnings << '\n';
}

int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
