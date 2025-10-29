#include <bits/stdc++.h>
using namespace std;
#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define all(x) x.begin(), x.end()
#define int long long
#define pii pair<int, int>
#define f first
#define s second

const int LINF = 0x3f3f3f3f3f3f3f3fll;
typedef vector<int> vi;

typedef tuple<int, int, int, int> t4i;
typedef tuple<int, int, int> t3i;
vector<vector<t3i>> adj;

int djikstra(vi &vis, int vAtual, int tInicial, int vFinal)
{
    priority_queue<t4i, vector<t4i>, greater<t4i>> pq;
    pq.emplace(tInicial, vAtual, -1, -1);
    vis[vAtual] = 1;

    while (!pq.empty())
    {
        auto [tAtual, v, x, y] = pq.top();
        pq.pop();

        if (vis[v] > 0 and y != -1) continue;

        if (y == -1 or tAtual % (x + y) < x)
        {
            vis[v] = 1;

            if (v == vFinal) return tAtual;
            for (auto [u, x1, y1] : adj[v])
            {
                if (vis[u] > 0) continue;
                pq.push({tAtual, u, x1, y1});
            }
        }

        else pq.emplace((tAtual + (x + y) - (tAtual % (x + y))), v, x, y);
    }
    return -1;
}

int32_t main()
{
    int n, m, t;
    cin >> n >> m >> t;

    adj.assign(n, vector<t3i>(0));
    for (int i = 0; i < m; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        a--, b--;
        adj[a].push_back({b, x, y});
        adj[b].push_back({a, x, y});
    }

    vi vis(n, 0);
    cout << djikstra(vis, 0, t, n - 1) << endl;

    return 0;
}
