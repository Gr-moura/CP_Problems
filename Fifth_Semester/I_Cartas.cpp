/*
ID: gabriel139
LANG: C++
TASK: test
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

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

bool memo [5][5][5][5][5][5][5][5];

// dp (a, b, c) = tem algum maior que abc?
void dp (int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0)
{
	bool ret = memo[a][b][c][d][e][f][g][h];
	if (ret) return;

	for (int i = a; i >= 0; i--)
	{
		for (int j = b; j >= 0; j--)
		{
			for (int k = c; k >= 0; k--)
			{
				for (int l = d; l >= 0; l--)
				{
					for (int m = e; m >= 0; m--)
					{
						for (int n = f; n >= 0; n--)
						{
							for (int o = g; o >= 0; o--)
							{
								for (int p = h; p >= 0; p--)
								{
									if (i == a and j == b and k == c and l == d and m == e and n  == f and o == g and p == h) continue;
									memo[i][j][k][l][m][n][o][p] = true;			
								}				
							}
						}
					}
				}				
			}
		}
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	set<string> s;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (s.contains(temp)) continue;
		s.insert(temp);

		vector<int> d (8, 0);
		for (int j = 0; j < k; j++)
		{
			d[j] = temp[j] - '0';
		}

		dp(d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
	}

	int ans = 0;
	for (auto str: s)
	{
		vector<int> d (8, 0);
		for (int j = 0; j < k; j++)
		{
			d[j] = str[j] - '0';
		}

		if (memo[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]]) ans++;

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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
