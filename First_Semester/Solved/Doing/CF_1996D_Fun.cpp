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
    int n, x, ans = 0;
    cin >> n >> x;

    int maxSoma = 2 * x - 3;
    dbg(maxSoma);
    int ma, mb, mc;

    mb = maxSoma / 3;
    ma = mb - 1;
    mc = mb + 1;

    if (ma * mb + mb * mc + mc * ma > n)
    {
        int b = (int)sqrt((n + 1) / 3);
        maxSoma = 3 * b;
        dbg(maxSoma);
    }

    for (int i = 3; i < maxSoma; i++)
    {
        int sum = (i - 1) * (i - 2) / 2;
        ans += sum;
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
