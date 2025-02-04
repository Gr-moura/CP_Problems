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

void solve()
{
    int n;
    cin >> n;
    vector<int> graph;

    graph.resize(n, 0);

    int NO = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp--;

        if (temp != i)
            graph[temp]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (graph[i] == 0)
        {
            NO = 1;
        }
    }

    if (n == 1)
        NO = 0;

    if (NO)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
}

int32_t main()
{
    _ int t = 1;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
