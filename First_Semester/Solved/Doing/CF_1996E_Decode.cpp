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
    string a;
    cin >> a;

    int ans = 0;

    int n = a.size();

    vector<pii> pre(n + 1, pii(0, 0));

    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i];

        if (a[i] == '0')
            pre[i + 1].f++;
        else
            pre[i + 1].s++;
    }

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int zeros, uns;
            zeros = pre[j].f - pre[i].f;
            uns = pre[j].s - pre[i].s;

            if (zeros == uns)
            {
                ans += (n - j + 1) * (i + 1);
            }

            ans %= 1000000007;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
