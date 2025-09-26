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
int n, m;
void applyConst(vector<vi> &diff, int lx, int ly, int rx, int ry, int d)
{
    diff[lx][ly] += d;

    if (rx + 1 < n) diff[rx + 1][ly] -= d;

    if (ry + 1 < m) diff[lx][ry + 1] -= d;

    if (rx + 1 < n && ry + 1 < m) diff[rx + 1][ry + 1] += d;
}

void solve()
{
    cin >> n >> m;

    vector<vi> a(n + 1, vi(m + 1, 0));
    vector<vi> b(n, vi(m, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int lx, ly, rx, ry, d;
        cin >> lx >> ly >> rx >> ry >> d;
        lx--, ly--, rx--, ry--;

        applyConst(b, lx, ly, rx, ry, d);
    }

    vector<vi> c(n + 1, vi(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i + 1][j + 1] = c[i + 1][j] + c[i][j + 1] - c[i][j] + b[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << c[i][j] + a[i][j] << " ";
        }
        cout << endl;
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
