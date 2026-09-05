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

const int MOD = 1e9 + 7, MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

vector<vi> g;
vector<int> sz;
vector<vi> szVertices;
vi pai;

int dfs(int vAtual, int vPai)
{
    sz[vAtual]++;

    for (auto u : g[vAtual])
    {
        if (sz[u] == 0) sz[vAtual] += dfs(u, vAtual);
    }

    pai[vAtual] = vPai;
    return sz[vAtual];
}

void solve()
{
    int n;
    cin >> n;

    g = vector<vi>(n + 1);
    sz = vi(n + 1, 0);
    szVertices = vector<vi>(n + 1);
    pai = vi(n + 1, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);
    int qtRaizes = 0;
    for (int i = 1; i < n; i++)
    {
        if (sz[i] == 1) qtRaizes++;
        szVertices[sz[i]].pb(i);
    }

    if (qtRaizes >= 3)
    {
        cout << 0 << endl;
        return;
    }

    int ans = 4;
    int maxSize2 = 1;
    while (maxSize2 <= n && szVertices[maxSize2].size() == 2)
        maxSize2++;

    if (maxSize2 != 1 and szVertices[maxSize2].size() == 1) ans = 6;

    for (int i = maxSize2 + 1; i <= n; i++)
        if (szVertices[i].size())
        {
            ans *= 2;
            ans %= MOD;
        }

    cout << ans << endl;
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
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

#ifdef ONPC
        cout << "__________________________" << endl;
#endif
    }

    return 0;
}
