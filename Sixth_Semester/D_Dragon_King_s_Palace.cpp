/*
D. Dragon King's Palace => 2026-10-08
https://codeforces.com/gym/106540/problem/D
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

struct point
{
	int x, y, r;
	long double dist (point &o)
	{
		int Mx = max(x, o.x), mx = min(x, o.x);
		int My = max(y, o.y), my = min(y, o.y);

		return sqrtl(Mx * Mx + My * my);
	}
};

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	point um{a, b, c};

	cin >> a >> b >> c;
	point dois{a, b, c};

	int k; cin >> k;

	// Apart
	if (um.dist(dois) > um.r + dois.r)
	{
		if (max(2 * um.r, 2 * dois.r) >= k) return void(YES());
		return void(NO());
	}

	if (um.r + dois.r + um.dist(dois) >= k or 2 * max(um.r, dois.r) >= k) return void(YES());
	return void(NO());
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
