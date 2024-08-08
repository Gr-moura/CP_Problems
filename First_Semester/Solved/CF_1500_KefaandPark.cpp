#include <bits/stdc++.h>
#include <unordered_map>
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

const int MAX = 1e5 + 10;

int ans = 0;
int vertices, max_cats;

int caminho[MAX];

unordered_map<int, int> gatos;

vector<vector<int>> g(MAX);

void BFS(int s)
{
    memset(caminho, LINF, sizeof caminho);

    queue<int> q;
    q.push(s);

    caminho[s] = 0;

    if (gatos[s])
        caminho[s] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        bool leaf = 1;
        for (auto u : g[v])
        {
            if (caminho[u] == LINF)
            {
                leaf = 0;

                if (gatos[u] == 0)
                {
                    caminho[u] = 0;
                    q.push(u);

                    continue;
                }

                if (caminho[v] + 1 <= max_cats)
                {
                    caminho[u] = caminho[v] + 1;
                    q.push(u);
                    continue;
                }
            }
        }

        if (leaf && caminho[v] <= max_cats)
        {
            ans++;
        }
    }
}

void solve()
{
    cin >> vertices >> max_cats;

    for (int i = 0; i < vertices; i++)
        cin >> gatos[i];

    for (int i = 0; i < vertices - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a--, b--;

        g[a].pb(b);
        g[b].pb(a);
    }

    BFS(0);

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
