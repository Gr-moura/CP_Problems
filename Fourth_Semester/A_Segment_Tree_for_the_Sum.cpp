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
int a[MAX];
int seg[4 * MAX];

int build(int p, int l, int r)
{
    if (l == r) return seg[p] = a[l];

    int mid = l + (r - l) / 2;
    return seg[p] = build(2 * p, l, mid) + build(2 * p + 1, mid + 1, r);
}

int query(int a, int b, int p, int l, int r)
{
    if (b < l or a > r) return 0;
    if (l >= a and r <= b) return seg[p];

    int mid = l + (r - l) / 2;
    return query(a, b, 2 * p, l, mid) + query(a, b, 2 * p + 1, mid + 1, r);
}

int update(int i, int v, int p, int l, int r)
{
    if (l == r and l == i) return seg[p] = v;
    if (i < l or i > r) return seg[p];

    int mid = l + (r - l) / 2;
    return seg[p] = update(i, v, 2 * p, l, mid) + update(i, v, 2 * p + 1, mid + 1, r);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int tipo;
        cin >> tipo;
        if (tipo == 1)
        {
            int i, v;
            cin >> i >> v;

            update(i, v, 1, 0, n - 1);
            continue;
        }

        int l, r;
        cin >> l >> r;
        cout << query(l, r - 1, 1, 0, n - 1) << endl;
    }
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
