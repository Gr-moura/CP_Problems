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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/* clang-format on */
// Link-cut Tree
//
// Link-cut tree padrao
//
// Todas as operacoes sao O(log(n)) amortizado

namespace lct
{
struct node
{
    int p, ch[2];
    node() { p = ch[0] = ch[1] = -1; }
};

node t[MAX];

bool is_root(int x)
{
    return t[x].p == -1 or (t[t[x].p].ch[0] != x and t[t[x].p].ch[1] != x);
}
void rotate(int x)
{
    int p = t[x].p, pp = t[p].p;
    if (!is_root(p)) t[pp].ch[t[pp].ch[1] == p] = x;
    bool d = t[p].ch[0] == x;
    t[p].ch[!d] = t[x].ch[d], t[x].ch[d] = p;
    if (t[p].ch[!d] + 1) t[t[p].ch[!d]].p = p;
    t[x].p = pp, t[p].p = x;
}
void splay(int x)
{
    while (!is_root(x))
    {
        int p = t[x].p, pp = t[p].p;
        if (!is_root(p)) rotate((t[pp].ch[0] == p) ^ (t[p].ch[0] == x) ? x : p);
        rotate(x);
    }
}
int access(int v)
{
    int last = -1;
    for (int w = v; w + 1; last = w, splay(v), w = t[v].p)
        splay(w), t[w].ch[1] = (last == -1 ? -1 : v);
    return last;
}
int find_root(int v)
{
    access(v);
    while (t[v].ch[0] + 1)
        v = t[v].ch[0];
    return splay(v), v;
}
void link(int v, int w)
{ // v deve ser raiz
    access(v);
    t[v].p = w;
}
void cut(int v)
{ // remove aresta de v pro pai
    access(v);
    t[v].ch[0] = t[t[v].ch[0]].p = -1;
}
int lca(int v, int w)
{
    return access(v), access(w);
}
} // namespace lct

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        if (s == "lca")
        {
            int u, v;
            cin >> u >> v;

            cout << lct::lca(u, v) << endl;
        }

        else if (s == "link")
        {
            int u, v;
            cin >> u >> v;

            lct::link(u, v);
        }

        else if (s == "cut")
        {
            int u;
            cin >> u;

            lct::cut(u);
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
