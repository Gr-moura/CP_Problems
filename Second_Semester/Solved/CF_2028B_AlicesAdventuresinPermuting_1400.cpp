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
    int n, b, c;
    cin >> n >> b >> c;

    if (b == 0 && c < n - 2)
    {
        cout << "-1\n";
        return;
    }

    if (n == 1)
    {
        if (c == 0)
        {
            cout << 0 << endl;
            return;
        }

        cout << 1 << endl;
        return;
    }

    if (b != 0)
    {
        if (c >= n)
        {
            cout << n << endl;
            return;
        }

        int menores = (n - c + b - 1) / b;
        int ans = max(n - menores, (long long)0);
        cout << ans << endl;
        return;
    }

    if (b == 0 && c >= n)
    {
        cout << n << endl;
        return;
    }

    if (b == 0)
    {
        cout << n - 1 << endl;
        return;
    }
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
