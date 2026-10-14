/*
F. Tea Blend => 2026-10-10
https://codeforces.com/contest/2275/problem/F
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

// Crivo de Eratóstenes
//
// Encontra todos os primos de 2 até n em O(n log log n).
// Para cada primo i, marcamos seus múltiplos como compostos.
// Os números que não forem marcados ao final são primos.

const int MAX = 1'000'005;

// divi[x] == i: x é primo.
// divi[x] > 1: guarda o menor divisor primo de x.
//
// Complexidade: O(lim log log lim) em tempo e O(MAX) em memória.
// Requer: 1 <= lim < MAX.

int divi[MAX]; // Primeiro primo que divide n
void crivo(int lim)
{
    for (int i = 1; i <= lim; i++)
        divi[i] = i;

    for (int i = 2; i * i <= lim; i++)
    {
        if (divi[i] == i)
        {
            // Os múltiplos menores que i² já foram marcados.
            for (int j = i * i; j <= lim; j += i)
            {
                // A primeira marcação usa o menor divisor primo.
                if (divi[j] == j)
                    divi[j] = i;
            }
        }
    }
}

// Retorna os fatores primos com repetição, em ordem crescente.
// Para m == 1, retorna um vetor vazio.
//
// Complexidade: O(log m).
// Requer: crivo(lim) executado e 1 <= m <= lim.
// Exemplo: fat(60) retorna {2, 2, 3, 5}.
set<int> fat(int m)
{
    set<int> ret;

    while (m > 1)
    {
        if(ret.contains(divi[m])) ret.erase(divi[m]);
		else ret.insert(divi[m]);

        m /= divi[m];
    }

    return ret;
}

void solve() {
	int n; cin >> n;
	vi a(n); for (auto &i : a) cin >> i;

	set<int> prefAtual;
	map<set<int>, int> pref;

	for (int i = 0; i < n; i++)
	{
		// Fatores ímpares de a[i]
		set<int> fAtual = fat(a[i]);

		for (auto fator: fAtual)
		{
			if (prefAtual.contains(fator)) prefAtual.erase(fator);
			else prefAtual.insert(fator);
		}

		if (prefAtual.size() < 8)
			pref[prefAtual]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		set<int> fAtual = fat(a[i]);
		ans += pref[fAtual];
	}

	cout << ans << endl;
}

int32_t main()
{
	crivo(MAX);

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
