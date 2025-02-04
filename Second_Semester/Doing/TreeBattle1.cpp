#include <bits/stdc++.h>

using namespace std;

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'
#define all(x) x.begin(), x.end()
#define int long long
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> graph;
vector<int> vis;
int ans = 0;
int maxDepth = -1;

void findMaxDepth(int root, int depth)
{
    if (depth > maxDepth)
        maxDepth = depth;

    vis[root] = 1;

    for (int v : graph[root])
    {
        if (!vis[v])
        {
            findMaxDepth(v, depth + 1);
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vis.resize(n, 0);
    graph.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a].pb(b);
        graph[b].pb(a);
    }

    findMaxDepth(0, 1);

    cout << (maxDepth + 1) / 2 << endl;
}

int32_t main()
{
    _ int t = 1;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}