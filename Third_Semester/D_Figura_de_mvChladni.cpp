#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* clang-format off */
#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/* clang-format on */
void solve()
{
	int n, m;
	cin >> n >> m;

	set<pii> pares;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;

		pares.insert({min(a, b), max(a, b)});
	}

	vi divisores;
	divisores.pb(1);
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			divisores.pb(i);
			divisores.pb(n / i);
		}
	}

	int obj = pares.size();
	for (auto d : divisores)
	{
		int dentro = 0;
		for (auto [a, b] : pares)
		{
			a = (a + d) % n;
			b = (b + d) % n;

			if (pares.find(make_pair(min(a, b), max(a, b))) == pares.end())
			{
				break;
			}
			dentro++;
		}

		// Se a quantidade de elementos nao for igual, existem elementos faltando para ser igual ao original
		if (dentro == obj)
		{
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int32_t main()
{
	// casas decimais
	// cout << fixed << setprecision(1);

	// horario
	// cout << setfill('0') << setw(2);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

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
