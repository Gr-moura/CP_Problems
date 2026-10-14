/*
Message Route => 2026-09-16
https://cses.fi/problemset/task/1667
*/

/* clang-format off */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class Key, class Cmp = less<Key>>
using ordered_set = tree<Key, null_type, Cmp, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <class Key, class Value, class Cmp = less<Key>>
using ordered_map = tree<Key, Value, Cmp, rb_tree_tag,
                         tree_order_statistics_node_update>;

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
typedef vector<vi> vvi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

#include <bits/stdc++.h>
using namespace std;

// Dijkstra
//
// Calcula a menor distância do vértice inicial a todos os vértices alcançáveis
// em um grafo com pesos não negativos
//
// O((n + m) log(m)), onde n é o número de vértices e m o número de arestas
// alcançáveis a partir do vértice inicial
//
// g[v] contém pares {u, peso}, representando uma aresta de v para u
// Ao final, minDist[v] guarda a menor distância até v, ou LINF se v for inalcançável
// Para uma nova execução, minDist deve ser reinicializado com LINF

using pii = pair<int, int>;
const int MAX = 2e5 + 10;
const int LINF = 0x3f3f3f3f;

vector<int> minDist(MAX, LINF);
vector<vector<pii>> g(MAX);

void djikstra(int vInicial)
{
    // Min-heap de pares {custoAtual, vértice}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

	minDist[vInicial] = 0;
	pq.push({0, vInicial});

	while (!pq.empty())
	{
		// Extrai o vértice de menor custo
		auto [custoAtual, vAtual] = pq.top();
		pq.pop();

		// Se estamos em uma solução pior, ignoramos
		if (custoAtual > minDist[vAtual])
			continue;

		// Gera novas distâncias a partir dos vizinhos de vAtual
		for (auto [u, custoAresta] : g[vAtual])
		{
			int novoCusto = custoAtual + custoAresta;
			if (novoCusto < minDist[u])
			{
				minDist[u] = novoCusto;
				pq.push({novoCusto, u});
			}
		}
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		a--, b--;

		g[a].pb(b); g[b].pb(a);
	}

	for 
	
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

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
