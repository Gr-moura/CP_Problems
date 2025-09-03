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

int combinacao (int n, int k)
{
	if (k > n) return 0;
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;

	int ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}

/* clang-format on */
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int somarLinha = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'C')
            {
                somarLinha++;
            }
        }

        if (somarLinha >= 2) ans += combinacao(somarLinha, 2);
    }

    for (int j = 0; j < n; j++)
    {
        int somarColuna = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i][j] == 'C')
            {
                somarColuna++;
            }
        }

        if (somarColuna >= 2) ans += combinacao(somarColuna, 2);
    }

    cout << ans << endl;
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
