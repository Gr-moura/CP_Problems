/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void applyConst(vi &diff, int n, int l, int r, int d)
{
    diff[l] += d;
    if (r + 1 < n) diff[r + 1] -= d;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    for (auto &i : a)
        cin >> i;

    vector<tuple<int, int, int>> ops(m);
    for (int i = 0; i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;

        ops[i] = {l, r, d};
    }

    vi dOps(m, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        applyConst(dOps, m, x, y, 1);
    }

    partial_sum(all(dOps), dOps.begin());
    vi b(n, 0);

    for (int i = 0; i < m; i++)
    {
        auto [l, r, d] = ops[i];
        applyConst(b, n, l, r, d * dOps[i]);
    }

    partial_sum(all(b), b.begin());
    for (int i = 0; i < n; i++)
        cout << a[i] + b[i] << " ";

    cout << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
