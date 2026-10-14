/*
Grid Path Description => 2026-09-24
https://cses.fi/problemset/task/1625
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
int ans = 0;
string s;
const int N = 7;
bool grid[N + 2][N + 7];

void dfs(int y, int x, int posAtual)
{
	if (grid[y][x]) return;

	if (posAtual == N * N - 1) return void(ans++);
	if (y == N and x == 1) return;

	bool up = grid[y - 1][x];
	bool down = grid[y + 1][x];
	bool left = grid[y][x - 1];
	bool right = grid[y][x + 1];

	if (up and down and !left and !right) return;
	if (!up and !down and left and right) return;

	char c = s[posAtual];

	grid[y][x] = true;

	if (c == 'U' or c == '?') dfs(y - 1, x, posAtual + 1);
	if (c == 'D' or c == '?') dfs(y + 1, x, posAtual + 1);
	if (c == 'L' or c == '?') dfs(y, x - 1, posAtual + 1);
	if (c == 'R' or c == '?') dfs(y, x + 1, posAtual + 1);
	
	grid[y][x] = false;
}

void solve() {
	cin >> s;

	for (int i = 0; i <= N + 1; i++)
	{
		grid[i][0] = grid[i][N + 1] = true;
		grid[0][i] = grid[N + 1][i] = true;
	}

	dfs(1, 1, 0);
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
