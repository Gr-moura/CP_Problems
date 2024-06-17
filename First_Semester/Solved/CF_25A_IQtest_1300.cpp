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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int n;
    cin >> n;
    int par = 0;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    for (int i = 0; i < 3; i++)
    {
        if (v[i] % 2 == 0)
        {
            par++;
        }
    }

    if (par >= 2)
        par = 1;
    else
        par = 0;

    for (int i = 1; i <= n; i++)
    {
        if (v[i - 1] % 2 == par)
        {
            cout << i;
            return;
        }
    }
}

int32_t main()
{
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
