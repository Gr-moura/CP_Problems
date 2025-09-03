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

int n, m;

/* clang-format on */
vector<pii> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valido(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void solve()
{
	cin >> n >> m;

	vector<string> letrasObj;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		letrasObj.pb(temp);
	}

	vector<vector<char>> letrasMod(n, vector<char>(m, 'W'));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			letrasMod[i].pb('W');
		}
		cout << endl;
	}

	vector<vector<int>> quadro(n, vector<int>(m, 2));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			for (auto p : mov)
			{
				int nx = p.f + i;
				int ny = p.s + j;

				if (valido(nx, ny))
				{
					char &l = letrasMod[nx][ny];
					if (l == 'W')
					{
						l = 'B';
					}
					else
						l = 'W';
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (letrasMod[i][j] != letrasObj[i][j])
			{
				quadro[i][j] = 3;
			}
		}
	}

	cout << 1 << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << quadro[i][j];
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
