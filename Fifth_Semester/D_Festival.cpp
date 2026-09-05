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

int MAX_VERTICES = 2e5 + 10;
int LOG_MAX_VERTICES = 30; 
int numVertices, tempo;
vector<vector<int>> adj(MAX_VERTICES), anc(LOG_MAX_VERTICES, vector<int>(MAX_VERTICES, 0));
vector<int> in(MAX_VERTICES), out(MAX_VERTICES), sz(MAX_VERTICES), depth(MAX_VERTICES, -1);

void dfs(int vAtual, int vPai) // O(N)
{
    in[vAtual] = tempo++;

	if (vPai != -1) depth[vAtual] = 1 + depth[vPai];

    for (int u : adj[vAtual])
    {
        if (u != vPai)
        {
            anc[0][u] = vAtual;
            dfs(u, vAtual);
        }
    }

    out[vAtual] = tempo++;
	sz[vAtual] = (out[vAtual] - in[vAtual] + 1) / 2;
}

void buildBL() // O(NlogN)
{
    tempo = 0;
	depth[0] = 0;
    dfs(0, -1);

    for (int k = 1; k < LOG_MAX_VERTICES; k++)
    {
        for (int i = 0; i < numVertices; i++)
        {
			// O oitavo ancestral de i é o quarto ancestral do quarto ancestral de i
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
        }
    }
}

bool isAncestor(int a, int b) // O(1)
{
	// Um vértice a é ancestral de b se o tempo de entrada de a for menor ou igual ao 
	// tempo de entrada de b e o tempo de saída de a for maior ou igual ao tempo de saída de b
    
	if (in[a] <= in[b] and out[a] >= out[b]) return true;
    return false;
}

int LCA(int a, int b) // O(NlogN)
{
    if (isAncestor(a, b)) return a;
    if (isAncestor(b, a)) return b;

	// Pegamos o maior ancestral de a que não é ancestral de b
    for (int k = LOG_MAX_VERTICES - 1; k >= 0; k--)
    {
        if (isAncestor(anc[k][a], b)) continue;
        a = anc[k][a];
    }

    return anc[0][a];
}

int dist(int a, int b) // O (NlogN)
{
	return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}

int kthAncestor(int k, int a) // O(NlogN)
{
	// Se o bit i de k for 1, subimos para o 2^i-ésimo ancestral de a
	for (int i = LOG_MAX_VERTICES - 1; i >= 0; i--)
	{
		if (k & (1ULL << i)) a = anc[i][a];
	}

	return a;
}

void solve() {
	cin >> numVertices;
	
	int q;
	cin >> q;

	for (int i = 0; i < numVertices - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	buildBL();

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;

		if (dist(a, b) % 2) cout << 0 << endl;

		else if (depth[a] == depth[b])
		{
			int k = dist(a, b) / 2;
			cout << numVertices - sz[kthAncestor(k - 1, a)] - sz[kthAncestor(k - 1, b)] << endl;
		}

		else 
		{
			int k = dist(a, b) / 2;

			if (depth[a] < depth[b]) swap(a, b);
			cout << sz[kthAncestor(k, a)] - sz[kthAncestor(k - 1, a)] << endl;
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
