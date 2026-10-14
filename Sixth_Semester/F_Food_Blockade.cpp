/*
F. Food Blockade => 2026-09-18
https://codeforces.com/gym/106552/problem/F
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
struct dinitz {
	const bool scaling = true;

	int lim;
	struct edge {
		int to, cap, rev, flow = 0;
		bool res;
		edge (int to_, int cap_, int rev_, bool res_) : to(to_), cap(cap_), rev(rev_), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c)
	{
		g[a].eb(b, c, g[b].size(), false);
		g[b].eb(a, 0, g[a].size() - 1, true);
	}

	bool bfs(int s, int t)
	{
		lev = vi (g.size(), -1); lev[s] = 0;
		beg = vi (g.size(), 0);
		queue<int> q; q.push(s);

		while (q.size())
		{
			int u = q.front(); q.pop();
			for (auto &i: g[u])
			{
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}

		return lev[t] != -1;
	}

	int dfs(int v, int s, int f = INF)
	{
		if (!f or v == s) return f;
		for (int &i = beg[v]; i < g[v].size(); i++)
		{
			auto &e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;

			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}

		return 0;
	}

	ll max_flow(int s, int t)
	{
		for (lim = scaling ? (1 << 30): 1; lim; lim /= 2)
		while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		
		return F;
	}
};

void solve() {
	int n, m; cin >> n >> m;

	dinitz d1(n + 2), d2(n + 2);
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--, v--;

		d1.add(u, v, 1);
		d1.add(v, u, 1);

		d2.add(u, v, 1);
		d2.add(v, u, 1);
	}

	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	a1--, a2--, b1--, b2--;

	d1.add(a1, b1, INF);
	d1.add(b1, a1, INF);
	d1.add(a2, b2, INF);
	d1.add(b2, a2, INF);

	d2.add(a1, b2, INF);
	d2.add(b2, a1, INF);
	d2.add(a2, b1, INF);
	d2.add(b1, a2, INF);

	// n = s, n + 1 = t
	d1.add(n, a1, INF);
	d1.add(n, b1, INF);
	d1.add(a2, n + 1, INF);
	d1.add(b2, n + 1, INF);

	d2.add(n, a1, INF);
	d2.add(n, b2, INF);
	d2.add(a2, n + 1, INF);
	d2.add(b1, n + 1, INF);

	int mi = (d2.max_flow(n, n + 1));
	cout << mi << endl;
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
