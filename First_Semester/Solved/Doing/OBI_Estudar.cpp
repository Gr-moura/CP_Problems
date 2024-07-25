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
    int n;
    cin >> n;

    vi hs(n + 2, 0);

    for (int i = 1; i <= n; i++)
        cin >> hs[i];

    auto it = unique(all(hs));

    int N = (int)distance(hs.begin(), it);
    hs.resize(N);

    vector<int> cs;

    for (int i = 1; i < N - 1; i++)
        if ((hs[i - 1] < hs[i] and hs[i] > hs[i + 1]) || (hs[i - 1] > hs[i] and hs[i] < hs[i + 1]))
            cs.pb(hs[i]);

    if (cs.size() % 2)
        cs.pb(0);

    vector<pii> es;
    int OPEN = 1, CLOSE = -1, ans = 1, open = 0;

    for (size_t i = 0; i < cs.size(); i += 2)
    {
        es.pb(pii(cs[i + 1], OPEN));
        es.pb(pii(cs[i], CLOSE));
    }

    sort(all(es));

    for (auto e : es)
    {
        open += e.second;
        ans = max(ans, open);
    }

    cout << ans + 1;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
