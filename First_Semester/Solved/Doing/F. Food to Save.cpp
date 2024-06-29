#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
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
vector<vector<int>> caminho(100);

vi vis(MAX);

int ans = 0;

void DFS(int v)
{
    vis[v] = 1;

    for (auto w : g[v])
    {
        if (vis[w] == 0)
        {
            caminho[w % 100] = caminho[v % 100];
            caminho[w % 100].pb(v);
            DFS(w);

            for (auto i : caminho[w % 100])
            {
                if (w < i)
                    ans++;
            }
            caminho[w % 10].clear();
        }
    }
}
void solve()
{
    int vertices;
    cin >> vertices;

    for (int i = 0; i < vertices - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    DFS(0);

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
