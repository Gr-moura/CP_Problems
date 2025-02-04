#include <bits/stdc++.h>
using namespace std;

class DSU
{
  public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if (rx != ry)
        {
            if (rank[rx] < rank[ry])
            {
                parent[rx] = ry;
            }
            else if (rank[rx] > rank[ry])
            {
                parent[ry] = rx;
            }
            else
            {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    }
};

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU dsuF(n), dsuG(n);

    // Read edges of F
    for (int i = 0; i < m1; ++i)
    {
        int u, v;
        cin >> u >> v;
        dsuF.unite(u, v);
    }

    // Read edges of G
    for (int i = 0; i < m2; ++i)
    {
        int u, v;
        cin >> u >> v;
        dsuG.unite(u, v);
    }

    vector<pair<int, int>> operations;

    // Add missing connections to match both F and G
    for (int u = 1; u <= n; ++u)
    {
        for (int v = u + 1; v <= n; ++v)
        {
            bool connectedInF = (dsuF.find(u) == dsuF.find(v));
            bool connectedInG = (dsuG.find(u) == dsuG.find(v));

            if (!connectedInF && !connectedInG)
            {
                // Add edge to both F and G
                dsuF.unite(u, v);
                dsuG.unite(u, v);
                operations.emplace_back(u, v);
            }
        }
    }

    // Output the result
    cout << operations.size() << '\n';
    for (auto [u, v] : operations)
    {
        cout << u << " " << v << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
