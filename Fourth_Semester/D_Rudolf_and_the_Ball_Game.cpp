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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, m, x;
int mod(int x, int n)
{
    int r = x % n;
    if (r == 0) return n;
    if (r < 0) return r + n;
    return r;
}

void applyChange(vector<bool> &pa, int r, char c)
{
    vector<bool> alcancados(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!pa[i]) continue;

        if (c == '0') alcancados[mod(i + r, n)] = true;
        else if (c == '1') alcancados[mod(i - r, n)] = true;
        else alcancados[mod(i + r, n)] = true, alcancados[mod(i - r, n)] = true;
    }

    pa = alcancados;
}

void solve()
{
    cin >> n >> m >> x;

    vector<bool> players(n + 1, 0);
    players[x] = true;

    for (int i = 0; i < m; i++)
    {
        int r;
        cin >> r;

        char c;
        cin >> c;

        applyChange(players, r, c);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += players[i];

    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (players[i]) cout << i << " ";
    cout << endl;
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
