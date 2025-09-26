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
int n;
void applyConst(vi &diff, int l, int r, int d)
{
    diff[l - 1] += d;

    if (r == n) return;
    diff[r] -= d;
}

void solve()
{
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vi diff(n, 0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;

        applyConst(diff, l, r, d);
    }

    partial_sum(diff.begin(), diff.end(), diff.begin());
    for (int i = 0; i < n; i++)
        cout << diff[i] + a[i + 1] << " ";
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
