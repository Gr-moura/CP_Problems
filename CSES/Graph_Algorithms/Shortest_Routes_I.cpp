/*
ID: gabriel139
LANG: C++
TASK: test
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

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

// Given DAG G & vertex s, compute minDist(v), for all v e V
// Subproblems: minDist(v), for each v e V
// Relate: minDist(v) = min { minDist(u) + w (u, v) | u e adj-(v) } U { LINF }
// Top. Order: Topological Order of DAG G
// Base: minDist(s) = 0
// Original Problem: All subproblems
// Time: O(|V| + |E|)

vector<int> minDist (MAX, LINF);
vector<vector<pii>> g(MAX);

void djikstra(int vInicial)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({vInicial, 0});

	while (!pq.empty())
	{
		auto [custoAtual, vAtual] = pq.top();
		pq.pop();

		if (custoAtual >= minDist[vAtual]) continue;
		minDist[vAtual] = custoAtual;

		for (auto [u, custoAresta]: g[vAtual])
		{
			int novoCusto = custoAtual + custoAresta;
			if (minDist[u] > novoCusto)
				pq.push({custoAtual + custoAresta, u});
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;

		g[a].eb(b, c);
	}

	djikstra(0);
	for (int i = 0; i < n; i++) cout << minDist[i] << " ";
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
