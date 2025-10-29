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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 3e5 + 10;
const int MAX2 = 30;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

vector<vector<pii>> g(MAX);
int n, p;
int pai[MAX2][MAX];
int edg[MAX2][MAX];
int in[MAX], out[MAX];

void dfs(int vAtual)
{
    in[vAtual] = p++;
    for (int i = 0; i < (int)g[vAtual].size(); i++)
        if (in[g[vAtual][i].f] == -1)
        {
            pai[0][g[vAtual][i].f] = vAtual;
            edg[0][g[vAtual][i].f] = g[vAtual][i].s;

            dfs(g[vAtual][i].f);
        }
    out[vAtual] = p++;
}

void build(int raiz)
{
    for (int i = 0; i < n; i++)
        pai[0][i] = i;
    p = 0, memset(in, -1, sizeof in);
    memset(edg, INF, sizeof edg);
    dfs(raiz);

    // pd dos pais
    for (int k = 1; k < MAX2; k++)
        for (int i = 0; i < n; i++)
        {
            pai[k][i] = pai[k - 1][pai[k - 1][i]];
            edg[k][i] = min(edg[k - 1][i], edg[k - 1][pai[k - 1][i]]);
        }
}

bool anc(int a, int b)
{ // se a eh ancestral de b
    return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b)
{
    int w1 = LINF; // menor aresta de a para LCA;
    for (int k = MAX2 - 1; k >= 0; k--)
    {
        if (anc(pai[k][a], b)) continue;

        w1 = min(w1, edg[k][a]);
        a = pai[k][a];
    }

    w1 = min(w1, edg[0][a]);
    if (pai[0][a] == b) return w1;

    int w2 = LINF; // menor aresta de b para LCA;
    for (int k = MAX2 - 1; k >= 0; k--)
    {
        if (anc(pai[k][b], a)) continue;

        w2 = min(w2, edg[k][b]);
        b = pai[k][b];
    }

    w2 = min(w2, edg[0][b]);
    if (pai[0][b] == a) return w2;

    return min(w1, w2);
}

void solve()
{
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    build(0);

    int q;
    cin >> q;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        cout << lca(a, b) << endl;
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
    cout.tie(0);

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
