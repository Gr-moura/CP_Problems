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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

struct DSU
{
    vector<int> id, sz;

    DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

    int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};

vector<vi> g(MAX);
vector<bool> vis(MAX, false);


void dfs(DSU &dsu, int vAtual)
{
	vis[vAtual] = true;
	for (auto u: g[vAtual])
	{
		if (!vis[u])
		{
			dsu.unite(u, vAtual);
			dfs(dsu, u);
		}
	}
}

void solve() {
	// Vamos guardar DSU's que indicam grupos de vértices conectados apenas
	// por arestas vermelhas. Assim, para transformar um ruim em um bom,
	// basta multiplicar por n - tamanho do grupo ruim e para manter ruim, basta
	// multiplicar pelo tamanho do mesmo grupo.

	int n, k; cin >> n >> k;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		a--, b--;

		if (c) continue;

		g[a].pb(b);
		g[b].pb(a);
	}

	DSU dsu(n);
	for (int i = 0; i < n; i++)
	{
		if(!vis[i]) dfs(dsu, i);
	}

	// O(n * k)
	// b[i] = Somatorio (nb[i - 1][j] * (n - size[j]) * n ^ (k - i))

	// nb[i][j] = nb[i - 1][j] * size[j]

	// Caminhos não bons de i vertices do grupo j
	vector<vi> nb(k, vi (n, 0));
	for (int i = 0; i < n; i++) nb[1][i] = dsu.sz[dsu.id[i]];

	for (int i = 2; i < k; i++)
	{
		vi jaComputado(n, false);
		for (int j = 0; j < n; j++)
		{
			if (jaComputado[dsu.id[j]]) continue;
			jaComputado[dsu.id[j]] = true;

			nb[i][dsu.id[j]] = nb[i - 1][dsu.id[j]] * dsu.sz[dsu.id[j]];
			nb[i][dsu.id[j]] %= MOD;
		}
	}

	vi powNK(k + 1, 1);
	for (int i = 1; i <= k; i++) 
	{	
		powNK[i] = powNK[i - 1] * n;
		powNK[i] %= MOD;
	}

	// Caminhos que ficaram bons no i-esimo elemento
	vi b(k + 1, 0);
	for (int i = 2; i <= k; i++)
	{
		int soma = 0;
		vi jaComputado(n, false);
		for (int j = 0; j < n; j++)
		{
			if (jaComputado[dsu.id[j]]) continue;
			jaComputado[dsu.id[j]] = true;

			soma += (((nb[i - 1][dsu.id[j]] * (n - dsu.sz[dsu.id[j]])) % MOD) * powNK[k - i]) % MOD;
			soma %= MOD;
		}

		b[i] = soma;
	}

	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans += (b[i]);
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
 
    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
