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

const int MAX = 2e5 + 10;
int n;
vi nums;

map<pii, int> memo;

// 0, n = 0
// max (anterior + pegar ele, anterior + nao pegar ele)

int dp(int fim, int ultimo)
{
    if (fim == n)
        return 0;

    if (memo[{fim, ultimo}] != 0)
        return memo[{fim, ultimo}];

    if (ultimo + 1 == nums[fim])
    {
        return memo[{fim, ultimo}] = max(dp(fim + 1, nums[fim]) + 1, dp(fim + 1, ultimo));
    }

    return memo[{fim, ultimo}] = dp(fim + 1, ultimo);
}

void solve()
{
    cin >> n;

    nums.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    pii ans = {0, 0};
    for (int i = 0; i < n; i++)
    {
        if (dp(i, nums[i]) >= ans.f)
        {
            ans.f = dp(i, nums[i]);
            ans.s = i;
        }
    }

    cout << ans.f + 1 << endl;

    int anterior = nums[ans.s] - 1;

    for (int i = ans.s; i < n; i++)
    {
        if (nums[i] == anterior + 1)
        {
            cout << i + 1 << " ";
            anterior += 1;
        }
    }
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
