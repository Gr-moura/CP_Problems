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
	vector<vector<char>> onibus(n, vector<char>(5));
	bool stop = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> onibus[i][j];

		if (stop == 0 && onibus[i][0] == onibus[i][1] && onibus[i][0] == 'O')
		{
			onibus[i][0] = '+';
			onibus[i][1] = '+';
			stop = 1;
		}

		if (stop == 0 && onibus[i][3] == onibus[i][4] && onibus[i][3] == 'O')
		{
			onibus[i][3] = '+';
			onibus[i][4] = '+';
			stop = 1;
		}
	}

	if (!stop)
	{
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << onibus[i][j];
		}

		cout << endl;
	}
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
