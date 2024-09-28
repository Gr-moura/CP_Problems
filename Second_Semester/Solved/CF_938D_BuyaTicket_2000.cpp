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

vector<vector<pair<int, int>>> graph;
vector<int> prices;
vector<int> ans;

void Dijkstra(int n)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({-prices[i], i});
    }

    while (!pq.empty())
    {
        int u = pq.top().s;
        int dist = -pq.top().f;

        pq.pop();

        if (ans[u] <= dist)
            continue;

        ans[u] = dist;

        for (auto v : graph[u])
        {
            if (dist + v.s < ans[v.f])
                pq.push({-dist - 2 * v.s, v.f});
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    prices.resize(n);
    ans.resize(n, LINF);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    Dijkstra(n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
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
