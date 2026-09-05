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

const int MAXN = 1e5 + 10;

// seg[pos] = quanto adicionar no intervalo [ini, fim]
int seg[4 * MAXN];

void update(int pos, int ini, int fim, int p, int q, int val)
{
    // Caso base: intervalo totalmente fora do update
    if (q < ini || p > fim) return;

    // Caso base: intervalo totalmente dentro da query
    if (p <= ini && fim <= q) 
	{
		seg[pos] += val;
		return;
	}

    // Dividimos o intervalo em dois e consultamos os filhos
    int mid = ini + (fim - ini) / 2;
	int esq = 2 * pos, dir = 2 * pos + 1;

	update(esq, ini, mid, p, q, val);
	update(dir, mid + 1, fim, p, q, val);
}

int query(int pos, int ini, int fim, int id)
{
    if (id < ini or id > fim) return 0;
	if (ini == fim) return seg[pos];

    int mid = ini + (fim - ini) / 2;
	int esq = 2 * pos, dir = 2 * pos + 1;

	return seg[pos] + query(esq, ini, mid, id) + query(dir, mid + 1, fim, id);
}

void solve()
{
    int n, m;
    cin >> n >> m;

	memset(seg, 0, sizeof(seg));

    for (int i = 0; i < m; i++)
    {
        int tipo;
        cin >> tipo;
        if (tipo == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;

            update(1, 0, n - 1, l, r - 1, v);
            continue;
        }

        int id;
        cin >> id;
        cout << query(1, 0, n - 1, id) << endl;
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
