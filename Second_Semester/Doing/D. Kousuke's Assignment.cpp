#include "Headers.h"
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

void solve()
{
    int n;
    cin >> n;

    vi nums(n);
    for (auto &i : nums)
        cin >> i;

    int ans = 0;

    vi somas(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        somas[i] = somas[i - 1] + nums[i - 1];
    }

    int ultimo = -1;
    for (int r = 0; r < n; r++)
    {
        for (int l = ultimo + 1; l <= r; l++)
        {
            if (somas[r + 1] - somas[l] == 0)
            {
                ultimo = r;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
