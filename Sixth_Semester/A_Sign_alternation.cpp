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

#include <bits/stdc++.h>
using namespace std;

// SegTree de soma
// Query e Update em O(log(n))
// Build em O(n)

const int MAXN = 1e5 + 10;
struct node {
	int sumOdd, sumEven;
};

node seg[4 * MAXN];
int v[MAXN];

node merge(node n1, node n2)
{
	node resp;
	resp.sumOdd = n1.sumOdd + n2.sumOdd;
	resp.sumEven = n1.sumEven + n2.sumEven;
	
	return resp;
}

// pos: posição do nó atual na segtree
// ini, fim: intervalo, no vetor original, representado por este nó da árvore

// build(); -> Começamos na raiz, que representa o intervalo [0, n - 1]
void build(int pos, int ini, int fim)
{
    // Caso base: folha, achamos o valor diretamente do vetor original
    if (ini == fim) 
	{
		if (ini % 2) seg[pos].sumOdd = v[ini];
		else seg[pos].sumEven = v[ini];
		return;
	}

    // Dividimos o intervalo em dois e construímos os filhos
    int mid = ini + (fim - ini) / 2;
	int esq = 2 * pos, dir = 2 * pos + 1;

    build(esq, ini, mid);
    build(dir, mid + 1, fim);

    seg[pos] = merge(seg[esq], seg[dir]);
}

// Query na range [p, q] do vetor original (0-indexed)
// query(p, q); -> Começamos na raiz, que representa o intervalo [0, n - 1]
node query(int pos, int ini, int fim, int p, int q)
{
    // Caso base: intervalo totalmente fora da query
    if (q < ini || p > fim) return {0, 0};

    // Caso base: intervalo totalmente dentro da query
    if (p <= ini && fim <= q) return seg[pos];

    // Dividimos o intervalo em dois e consultamos os filhos
    int mid = ini + (fim - ini) / 2;
	int esq = 2 * pos, dir = 2 * pos + 1;

    return merge(query(esq, ini, mid, p, q), query(dir, mid + 1, fim, p, q));
}

// Update na posição id do vetor original para o valor val
// update(id, val); -> Começamos na raiz, que representa o intervalo [0, n - 1]
void update(int pos, int ini, int fim, int id, int val)
{
    if (id < ini || id > fim) return;
	if (ini == fim) 
	{
		if (ini % 2) seg[pos].sumOdd = val;
		else seg[pos].sumEven = val;
		return;
	}

    int mid = ini + (fim - ini) / 2;
	int esq = 2 * pos, dir = 2 * pos + 1;

	update(esq, ini, mid, id, val);
	update(dir, mid + 1, fim, id, val);

    seg[pos] = merge(seg[esq], seg[dir]);
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    build(1, 0, n - 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tipo;
        cin >> tipo;
        if (tipo == 0)
        {
            int id, val;
            cin >> id >> val;

            update(1, 0, n - 1, id - 1, val);
            continue;
        }

        int p, q;
        cin >> p >> q;
        p--, q--;

        node result = query(1, 0, n - 1, p, q);
		if (p % 2) swap(result.sumOdd, result.sumEven);
        cout << result.sumEven - result.sumOdd << endl;
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
