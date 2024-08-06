#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0);
#define int long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define lb(v, x) (lower_bound(all(v), x) - v.begin())
#define ub(v, x) (upper_bound(all(v), x) - v.begin())

typedef vector<int> vi;
typedef pair<int, int> pii;

void solve()
{
    int E, D;
    cin >> E >> D;
    int ans;

    if (E > D)
        ans = E + D;
    else
        ans = 2 * (D - E);
    cout << ans;
}

int32_t main()
{
    _ int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
