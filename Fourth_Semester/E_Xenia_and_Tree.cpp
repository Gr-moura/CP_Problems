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

const int MOD = 1e9 + 7, MAX = 1e5 + 10, MAX2 = 20;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, tempo;
vector<vi> adj(MAX), anc(MAX2, vi(MAX, 0));
vi in(MAX), out(MAX);

void dfs(int vAtual, int vPai)
{
    in[vAtual] = tempo++;

    for (int u : adj[vAtual])
    {
        if (u != vPai)
        {
            anc[0][u] = vAtual;
            dfs(u, vAtual);
        }
    }

    out[vAtual] = tempo++;
}

void buildBL()
{
    tempo = 0;
    dfs(0, -1);

    for (int k = 1; k < MAX2; k++)
    {
        for (int i = 0; i < n; i++)
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
    if (isAncestor(a, b)) return b;

    for (int k = MAX2 - 1; k >= 0; k--)
    {
        if (isAncestor(anc[k][a], b)) continue;
        a = anc[k][a];
    }

    return anc[0][a];
}

int dist[MAX];
void calcDist(int inicial = 0)
{
    memset(dist, -1, sizeof dist);
    dist[inicial] = 0;

    queue<int> q;
    q.push(inicial);
    while (!q.empty())
    {
        int vAtual = q.front();
        q.pop();

        for (auto u : adj[vAtual])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[vAtual] + 1;
                q.push(u);
            }
        }
    }
}

int minDist[MAX];
vi vermelhos;
void BFS()
{
    memset(minDist, -1, sizeof minDist);
    queue<int> q;
    for (auto i : vermelhos)
        q.push(i), minDist[i] = 0;

    while (!q.empty())
    {
        int vAtual = q.front();
        q.pop();

        for (auto u : adj[vAtual])
        {
            if (minDist[u] == -1)
            {
                minDist[u] = minDist[vAtual] + 1;
                q.push(u);
            }
        }
    }
}

int distancia(int u, int v)
{
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

int ask(int vertice, vi &novosVermelhos)
{
    int ans = minDist[vertice];
    for (auto i : novosVermelhos)
    {
        ans = min(ans, distancia(vertice, i));
    }

    return ans;
}

void solve()
{
    int m;
    cin >> n >> m;

    int limite = sqrt(n * log2(n));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi novosVermelhos;

    novosVermelhos.pb(0);
    vermelhos.pb(0);

    buildBL();
    calcDist();
    BFS();

    for (int i = 0; i < m; i++)
    {
        int t, v;
        cin >> t >> v;
        v--;

        if (t == 2)
        {
            cout << ask(v, novosVermelhos) << endl;
            continue;
        }

        novosVermelhos.pb(v);
        vermelhos.pb(v);
        if (novosVermelhos.size() >= limite)
        {
            BFS();
            novosVermelhos.clear();
        }
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
