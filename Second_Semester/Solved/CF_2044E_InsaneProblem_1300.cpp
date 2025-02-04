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

void verQtsExistemParaX(int l1, int r1, int l2, int r2, int x, int &ans)
{
    int minL2 = l2 % x == 0 ? l2 : l2 + (x - l2 % x);
    int minL1 = minL2 / x;

    minL1 = minL1 < l1 ? l1 : minL1;

    if (minL1 > r1)
        return;

    int maxR2 = r2 - (r2 % x);
    int maxR1 = maxR2 / x;

    maxR1 = maxR1 > r1 ? r1 : maxR1;

    if (maxR1 < l1)
        return;

    ans += maxR1 - minL1 + 1;
}

void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    vector<int> possiveis;
    for (int i = 1; i <= r2 / l1; i *= k)
    {
        possiveis.pb(i);
    }

    int ans = 0;
    for (int i = 0; i < possiveis.size(); i++)
    {
        verQtsExistemParaX(l1, r1, l2, r2, possiveis[i], ans);
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
