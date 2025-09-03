/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
const int MOD = 1e9 + 7;

int restos[3];

// formas tamanho N, R
int dp[200000 + 10][3];

int formas(int n, int r)
{
    if (dp[n][r] != -1) return dp[n][r];

    int ans = 0;

    ans += formas(n - 1, 0) * restos[r];
    ans %= MOD;

    ans += formas(n - 1, 1) * restos[(3 + r - 1) % 3];
    ans %= MOD;

    ans += formas(n - 1, 2) * restos[(3 + r - 2) % 3];
    ans %= MOD;

    return dp[n][r] = ans;
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    memset(dp, -1, sizeof(dp));

    int primeiroR0 = l + (3 - (l % 3)) % 3;
    int primeiroR1 = l + (4 - (l % 3)) % 3;
    int primeiroR2 = l + (5 - (l % 3)) % 3;

    restos[0] = max(0ll, (r - primeiroR0 + 3) / 3);
    restos[1] = max(0ll, (r - primeiroR1 + 3) / 3);
    restos[2] = max(0ll, (r - primeiroR2 + 3) / 3);

    dp[1][0] = restos[0];
    dp[1][1] = restos[1];
    dp[1][2] = restos[2];

    cout << formas(n, 0);
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
