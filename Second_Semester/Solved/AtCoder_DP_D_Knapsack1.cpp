#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
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

int n, W;
vector<pii> items;

vector<vector<int>> memo;

int dp(int W, int i)
{
    if (i == n)
        return 0;

    if (memo[W][i])
        return memo[W][i];

    if (i < n && W < items[i].f)
        return dp(W, i + 1);

    return memo[W][i] = max(dp(W, i + 1), dp(W - items[i].f, i + 1) + items[i].s);
}

void solve()
{
    cin >> n >> W;
    items.resize(n);
    memo.resize(W + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
        cin >> items[i].f >> items[i].s;

    cout << dp(W, 0) << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
