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

const int MAX = 2e5 + 10;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

int funciona = 1;
void dfs(int v)
{
    vis[v] = true;
    if (g[v].size() != 2)
        funciona = 0;

    for (auto w : g[v])
    {
        if (vis[w] == false)
        {
            dfs(w);
        }
    }
}

void solve()
{
    int vertices, edges, ans = 0;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < vertices; i++)
    {
        if (g[i].size() != 0 && vis[i] == false)
        {
            dfs(i);
            if (funciona)
                ans++;
            funciona = 1;
        }
    }

    cout << ans;
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
