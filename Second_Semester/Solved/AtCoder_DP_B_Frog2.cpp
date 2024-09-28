#include <bits/stdc++.h>
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

int n, k;

vector<int> memo;
vector<int> heights;

int DP(int index)
{
    if (index <= 0)
        return 0;

    if (memo[index] != -1)
        return memo[index];

    int res = LINF;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
            res = min(res, DP(index - i) + abs(heights[index] - heights[index - i]));
    }
    return memo[index] = res;
}

void solve()
{
    cin >> n >> k;

    memo.resize(n, -1);
    heights.resize(n);

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    DP(n - 1);
    cout << memo[n - 1];
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
