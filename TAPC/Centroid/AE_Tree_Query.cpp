/*
ID: gabriel139
LANG: C++
TASK: test
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back

// Índice base 0 do primeiro elemento maior ou igual a x em log n
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())

// Índice base 0 do primeiro elemento  estritamente maior que x em log n
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

int MAX = 2e5 + 10;
int MAX2 = 30;

int numVertices, q, tempo;
vector<vector<pii>> adj(MAX);
vector<vi> anc(MAX2, vi(MAX, 0));
vi in(MAX), out(MAX);

vi distRoot(MAX);
vector<vi> distSub(MAX);
vector<vi> distPaiSub(MAX);

void dfs(int vAtual, int vPai, int dist)
{
    in[vAtual] = tempo++;
    distRoot[vAtual] = dist;

    for (auto [u, w] : adj[vAtual])
    {
        if (u != vPai)
        {
            anc[0][u] = vAtual;
            dfs(u, vAtual, dist + w);
        }
    }

    out[vAtual] = tempo++;
}

void buildBL()
{
    tempo = 0;
    dfs(0, -1, 0);

    for (int k = 1; k < MAX2; k++)
    {
        for (int i = 0; i < numVertices; i++)
        {
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
        }
    }
}

bool isAncestor(int a, int b)
{
    if (in[a] <= in[b] and out[a] >= out[b]) return true;
    return false;
}

int lca(int a, int b)
{
    if (isAncestor(a, b)) return a;
    if (isAncestor(b, a)) return b;

    for (int k = MAX2 - 1; k >= 0; k--)
    {
        if (isAncestor(anc[k][a], b)) continue;
        a = anc[k][a];
    }

    return anc[0][a];
}

int getDist(int u, int v)
{
    return distRoot[u] + distRoot[v] - 2 * distRoot[lca(u, v)];
}

struct centroid
{
    vector<bool> vis;
    vector<int> pai;
    vector<int> sz;
    int n;

    void init(int s)
    {
        n = s;
        vis = vector<bool>(n, 0);
        pai = vector<int>(n);
        sz = vector<int>(n);
    }

    int find_size(int v, int p = -1)
    {
        if (vis[v]) return 0;
        sz[v] = 1;

        for (auto [u, w] : adj[v])
        {
            if (u != p && !vis[u])
            {
                sz[v] += find_size(u, v);
            }
        }

        return sz[v];
    }

    int find_centroid(int v, int p, int n)
    {
        for (auto [u, w] : adj[v])
        {
            if (u != p && !vis[u] && sz[u] > n / 2)
            {
                return find_centroid(u, v, n);
            }
        }

        return v;
    }

    void build(int v = 0, int p = -1)
    {
        find_size(v);

        int c = find_centroid(v, -1, sz[v]);
        vis[c] = true;
        pai[c] = p;

        for (auto [u, w] : adj[c])
        {
            if (!vis[u])
            {
                build(u, c);
            }
        }
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    numVertices = n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    buildBL();

    centroid cd;
    cd.init(n);
    cd.build(0);

    for (int i = 0; i < n; i++)
    {
        int vAtual = i;
        while (vAtual != -1)
        {
            int d = getDist(i, vAtual);
            distSub[vAtual].pb(d);

            if (cd.pai[vAtual] != -1)
            {
                int dPai = getDist(i, cd.pai[vAtual]);
                distPaiSub[vAtual].pb(dPai);
            }

            vAtual = cd.pai[vAtual];
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(all(distSub[i]));
        sort(all(distPaiSub[i]));
    }

    for (int i = 0; i < q; i++)
    {
        int v, l;
        cin >> v >> l;
        v--;

        int ans = 0, vAtual = v, vAnterior = -1;
        while (vAtual != -1)
        {
            int distDoVAtual = getDist(v, vAtual);

            if (distDoVAtual <= l)
            {
                int rem = l - distDoVAtual;
                ans += ub(distSub[vAtual], rem);

                if (vAnterior != -1)
                {
                    ans -= ub(distPaiSub[vAnterior], rem);
                }
            }

            vAnterior = vAtual;
            vAtual = cd.pai[vAtual];
        }

        cout << ans << endl;
    }
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

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
