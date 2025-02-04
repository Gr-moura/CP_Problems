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
    int n, as, qs;
    cin >> n >> as >> qs;
    vi todas(n + 1, 1);
    vi a(as), q(qs);
    for (int i = 0; i < as; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < qs; i++)
    {
        cin >> q[i];
        todas[q[i]] = 0;
    }

    if (qs < n - 1)
    {
        for (int i = 0; i < as; i++)
        {
            cout << 0;
        }
        cout << endl;
        return;
    }

    if (qs == n)
    {
        for (int i = 0; i < as; i++)
        {
            cout << 1;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < as; i++)
    {
        cout << todas[a[i]];
    }
    cout << endl;
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
