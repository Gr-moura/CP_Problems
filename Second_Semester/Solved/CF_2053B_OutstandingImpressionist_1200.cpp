#include "Headers.h"
#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int n;
    cin >> n;
    vector<pii> impressions(n);
    unordered_map<int, int> iguais;
    int max_r = 0;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        impressions[i] = {l, r};
        if (l == r)
        {
            iguais[l]++;
        }
        max_r = max(max_r, r);
    }

    vector<int> prefix_sum(max_r + 2, 0);

    for (auto &p : iguais)
    {
        prefix_sum[p.first]++;
    }

    for (int i = 1; i <= max_r; i++)
    {
        prefix_sum[i] += prefix_sum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        int l = impressions[i].f;
        int r = impressions[i].s;

        if (l == r && iguais[l] > 1)
        {
            cout << 0;
            continue;
        }

        if (l == r)
        {
            cout << 1;
            continue;
        }

        int total_in_range = prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0);

        if (total_in_range == (r - l + 1))
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }

    cout << endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
