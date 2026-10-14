/*
D. Target Infection => 2026-10-10
https://codeforces.com/contest/2271/problem/D
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



void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<pii> inf;
	inf.pb({0, 0});
	for (int i = 0; i < n; i++)
	{
		int l, r; cin >> l >> r;
		inf.pb({l, r});
	}

	auto idProxInter = [&] (int x)
	{
		int l = 0, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;

			if (inf[mid].f <= x and inf[mid].s >= x) return make_pair(mid, true);
			if (inf[mid].s < x) l = mid + 1; 
			else r = mid - 1;
		}

		return make_pair(r, false);	
	};

	// Se esq está no vazio
	// Podemos sempre diminuir min(dist(dir, vazio), dist(esq, vazio));

	// Se esq está no infectado
	// Podemos sempre aumentar min(dist(esq, vazio), dist(dir, vazio))

	// Se com isso podemos alcançar k, paramos

	// Vamos sempre de rInfectadoi para lInfectadoi - 1

	// dist(l, vazio) = dist l ao próximo r

	// Como saber onde 

	int infAtual = 0, posAtual = inf.back().second + 1;
	while (infAtual != k)
	{
		if (posAtual == 1)
		{
			cout << -1 << endl;
			return;
		}

		int l = posAtual, r = posAtual + m - 1;
		auto [idL, isLinf] = idProxInter(l - 1);
		auto [idR, isRinf] = idProxInter(r);

		if (!isLinf)
		{
			int distLVazio = l - inf[idL].s;
			int distRVazio = max (0ll, r - inf[idR].s);
			
			int consigo = min (distLVazio, distRVazio);
			if (infAtual > k and infAtual - consigo <= k)
			{
				cout << l - (infAtual - k) << endl;
				return;
			}

			posAtual -= consigo;
			infAtual -= consigo;

			if (distLVazio == distRVazio) posAtual--;
			else if (distLVazio > distRVazio)
			{
				posAtual--;
			}

			else
			{
				posAtual--;
				infAtual++;
			}
		}

		if (isLinf)
		{
			int distLVazio = l - inf[idL].s;
			int distRVazio = max (0ll, r - inf[idR].s);
			
			int consigo = min (distLVazio, distRVazio);
			if (infAtual < k and infAtual + consigo >= k)
			{
				cout << l - (k - infAtual) << endl;
				return;
			}

			posAtual -= consigo;
			infAtual += consigo;

			if (distLVazio == distRVazio) posAtual--;
			else if (distLVazio > distRVazio)
			{
				posAtual--;
				infAtual++;
			}

			else
			{
				posAtual--;
				infAtual--;
			}
		}

	}

	cout << posAtual << endl;
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
