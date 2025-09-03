/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

int n;
vector<pii> distPorVertice;
vector<int> dist;
vector<vi> g;

void printarDistMenorQueX(int x)
{
    cout << x + 1 << " ";
    for (int i = 0; i <= x; i++)
    {
        cout << distPorVertice[i].s + 1 << " ";
    }

    cout << endl << endl;
    cout.flush();
}

int recebeRespostaPositiva()
{
    int x;
    cin >> x;

    return x;
}

void DFS(int v)
{
    for (auto u : g[v])
    {
        if (dist[u] == -1)
        {
            dist[u] = dist[v] + 1;
            distPorVertice.pb({dist[u], u});

            DFS(u);
        }
    }
}

void solve()
{
    cin >> n;
    g.resize(n);
    dist.resize(n, -1);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        g[a].pb(b);
        g[b].pb(a);
    }

    dist[0] = 0;
    distPorVertice.pb({0, 0});
    DFS(0);

    sort(all(distPorVertice));

    int l = 0, r = n - 1;
    while (l < r)
    {
        int m = (l + r) / 2;

        cout << "? ";
        printarDistMenorQueX(m);

        if (recebeRespostaPositiva())
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << "! " << l << endl;
    cout.flush();
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
