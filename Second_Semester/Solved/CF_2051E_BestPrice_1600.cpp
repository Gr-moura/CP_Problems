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

#define A 0
#define B 1

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pii> ev;
    vi a(n);
    vi b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ev.pb({a[i], A});
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        ev.pb({b[i], B});
    }

    sort(all(ev));

    int neg = 0;
    int comp = n;

    int ans = -1;
    for (int i = 0; i < 2 * n;)
    {
        pii p = ev[i];

        if (neg <= k)
        {
            ans = max(ans, p.f * comp);
        }

        while (i < 2 * n && ev[i].f == p.f)
        {
            neg += (ev[i].s == A);

            neg -= (ev[i].s == B);
            comp -= (ev[i].s == B);

            ++i;
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
