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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
const int MAXN = 1e5 + 10;
int pai[2 * MAXN], altura[MAXN * 2];
int eh_bipartido = 1;

void init()
{
    eh_bipartido = 1;
    for (int i = 0; i < MAXN * 2; i++)
        pai[i] = i, altura[i] = 0;
}

struct arestaTemporaria
{
    int u, v;
    int l, r;

    arestaTemporaria(int u, int v, int l, int r) : u(u), v(v), l(l), r(r) {}
};

// Guarda as arestas existentes
vector<pii> tree[MAXN * 4];

// Adiciona na árvore na range [x, y] a aresta e
void add(int id, int l, int r, int x, int y, pii e);

// Endereco que foi modificado e antigo valor
vector<pair<int *, int>> operacoes;

// Resetamos até termos uma quantidade x de operações já realizadas
void cancelaOperacao(int qt);

// Recebe uma aresta e retorna a última vez em que ela foi criada
map<pii, int> arestas;

// DSU
int find(int x);

// Junta ambos e guarda como era antes em operacoes
void _uni(int x, int y);

// Une, checando se é bipartido via 2-SAT
void uni(int x, int y);

void dfs(int id, int l, int r)
{
    int total = operacoes.size();
    for (auto [u, v] : tree[id])
        uni(u, v);

    if (l == r)
    {
        if (eh_bipartido) cout << "YES\n";
        else cout << "NO\n";

        cancelaOperacao(total);
        return;
    }

    int m = (l + r) / 2;
    dfs(id * 2, l, m);
    dfs(id * 2 + 1, m + 1, r);

    cancelaOperacao(total);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    init();

    vector<arestaTemporaria> ranges;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (u > v) swap(u, v);

        // Se já existe, remove
        if (arestas.count({u, v}))
        {
            int l = arestas[{u, v}];
            int r = i - 1; // Existia até o i anterior

            arestaTemporaria nova(u, v, l, r);
            ranges.pb(nova);

            arestas.erase({u, v});
            continue;
        }

        arestas[{u, v}] = i; // Insere agora;
    }

    for (auto [p, l] : arestas)
    {
        auto [u, v] = p;
        arestaTemporaria nova(u, v, l, q - 1); // Ficam vivas até o final
        ranges.pb(nova);
    }

    // Adicionar arestas à segtree
    for (auto r : ranges)
    {
        add(1, 0, q - 1, r.l, r.r, {r.u, r.v});
    }

    dfs(1, 0, q - 1);
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

void add(int id, int l, int r, int x, int y, pii e)
{
    if (l > y or r < x) return;
    if (x <= l and y >= r)
    {
        tree[id].pb(e);
        return;
    }

    int m = (l + r) / 2;

    add(id * 2, l, m, x, y, e);
    add(id * 2 + 1, m + 1, r, x, y, e);
}

void cancelaOperacao(int qt)
{
    while (operacoes.size() > qt)
    {
        auto ultimo = operacoes.back();
        operacoes.pop_back();

        *ultimo.f = ultimo.s;
    }
}

int find(int x)
{
    while (x != pai[x])
        x = pai[x];
    return x;
}

void _uni(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;

    if (altura[x] < altura[y]) swap(x, y);

    operacoes.eb(&pai[y], pai[y]);
    pai[y] = x;

    if (altura[x] == altura[y])
    {
        operacoes.eb(&altura[x], altura[x]);
        altura[x] += 1;
    }
}

void uni(int x, int y)
{
    _uni(x, y + MAXN);
    _uni(x + MAXN, y);

    if (find(x) == find(x + MAXN))
    {
        operacoes.eb(&eh_bipartido, eh_bipartido);
        eh_bipartido = 0;
    }
}