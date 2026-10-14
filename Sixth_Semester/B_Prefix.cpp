/*
B. Prefix => 2026-10-11
https://codeforces.com/contest/2274/problem/B
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
typedef vector<vi> vvi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve() {
	// Sempre escolhemos a maior ou a menor opcao
	int n;
	cin >> n;
	
	vi a(n);
	for (auto &i: a) cin >> i;

	int ans = a[0];
	vi minP(n + 1, a[0]), maxP(n + 1, a[0]);
	// A resposta sempre será a mais positiva ou a mais negativa
	for (int i = 2; i <= n; i++)
	{
		int maxA = max({a[i - 1], a[i - 1] + maxP[i - 1], a[i - 1] - maxP[i - 1]});
		int minA = min({a[i - 1], a[i - 1] + minP[i - 1], a[i - 1] - minP[i - 1]});
		
		minP[i] = minP[i - 1] + minA;
		maxP[i] = maxP[i - 1] + maxA;

		ans = max({ans, a[i - 1], maxA, a[i - 1] - minP[i - 1]});
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
