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
	int n;
	cin >> n;

	int soma = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		soma += temp - 1;
	}

	if (soma % 2)
	{
		cout << "errorgorn" << endl;
		return;
	}

	cout << "maomao90" << endl;
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
