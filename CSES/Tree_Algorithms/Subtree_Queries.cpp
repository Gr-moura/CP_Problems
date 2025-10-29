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
#define int unsigned long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, *v;
struct segtree
{
    ll seg[8 * MAX];

    ll build(int p = 1, int l = 0, int r = n - 1)
    {
        if (l == r) return seg[p] = v[l];

        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
    }

    ll query(int a, int b, int p = 1, int l = 0, int r = n - 1)
    {
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return 0;

        int m = (l + r) / 2;
        return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
    }

    ll update(int i, int x, int p = 1, int l = 0, int r = n - 1)
    {
        if (l == r and r == i) return seg[p] = x;
        if (i < l or r < i) return seg[p];

        int m = (l + r) / 2;
        return seg[p] = update(i, x, 2 * p, l, m) + update(i, x, 2 * p + 1, m + 1, r);
    }
};

int values[MAX];
int euler[2 * MAX];

map<int, pii> lr;
vector<vi> adj(MAX);

int hora = 0;
void dfs(int vAtual, int vPai)
{
    lr[vAtual].f = hora;
    euler[hora++] = values[vAtual];

    for (auto u : adj[vAtual])
    {
        if (u != vPai) dfs(u, vAtual);
    }

    lr[vAtual].s = hora;
    euler[hora++] = 0;
}

void solve()
{
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> values[i];

    // Construir o Euler Tour para descobrir entre quais valores será a soma;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    hora = 0;
    dfs(0, -1);

    v = euler;
    n *= 2;

    // Construir segtree com valores iniciais
    segtree seg;
    seg.build();

    for (int i = 0; i < q; i++)
    {
        int tipo;
        cin >> tipo;

        if (tipo == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;

            seg.update(lr[s].f, x);
        }

        if (tipo == 2)
        {
            int s;
            cin >> s;
            s--;

            auto [a, b] = lr[s];
            cout << seg.query(a, b) << endl;
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
