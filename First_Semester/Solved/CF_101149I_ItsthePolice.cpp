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
    int sq, st;
    cin >> sq >> st;

    vector<vector<int>> g(sq);

    for (int i = 0; i < st; i++)
    {
        int v, u;
        cin >> u >> v;
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    int menor = LINF;
    int ind_menor = 0;
    for (int i = 0; i < sq; i++)
    {
        if (sz(g[i]) <= menor)
        {
            menor = sz(g[i]);
            ind_menor = i;
        }
    }

    vector<int> pular = g[ind_menor];
    sort(all(pular));

    int j = 0;
    for (int i = 0; i < sq; i++)
    {
        if (i == ind_menor)
        {
            cout << " 0";
        }

        else if (j < sz(pular) && i == pular[j])
        {
            cout << " 0";
            j++;
        }

        else
            cout << " 1";
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
