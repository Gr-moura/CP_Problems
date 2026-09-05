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

const int MOD = 1e9 + 7, MAX = 40;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
set<pii> arestas;
map<int, int> sz;
map<int, vi> ansQuery;

vi query (int k)
{
	if (ansQuery.count(k)) return ansQuery[k];
	
	cout << "? " << k << endl;
	cout.flush();

	int q;
	cin >> q;

	vi ret(q);
	for (auto &i: ret) cin >> i;

	ansQuery[k] = ret;
	return ret;
}

bool in(int vAtual, vi& v)
{
	for (auto i: v) if (i == vAtual) return true;
	return false;
}

int entreiVertice(int vAtual, int kInicial, vi &ultimaQuery)
{
	if (sz[vAtual]) return kInicial + sz[vAtual];
	vi res = ultimaQuery;

	int tamanho = 1;
	int kAtual = kInicial + 1;
	res = query(kAtual);
	while (in(vAtual, res) and res.size() > ultimaQuery.size())
	{
		for (int i = 1; i < res.size(); i++)
			arestas.insert({res[i - 1], res[i]});

		int kNovo = entreiVertice(res.back(), kAtual, res);
		tamanho += kNovo - kAtual;
		
		kAtual = kNovo;
		res = query(kAtual);
	}

	sz[vAtual] = tamanho;
	// dbg(vAtual);
	// dbg(tamanho);
	return kAtual;
}

void solve() {
	int n;
	cin >> n;

	arestas.clear();
	sz.clear();
	ansQuery.clear();

	vi atual(1, 1);
	int kAtual = 1;
	while (atual.size())
	{
		kAtual = entreiVertice(atual.back(), kAtual, atual);
		atual = query(kAtual);
	}

	cout << "! " << arestas.size() << endl;
	cout.flush();

	for (auto p: arestas)
	{
		cout << p.f << " " << p.s << endl;
		cout.flush();
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