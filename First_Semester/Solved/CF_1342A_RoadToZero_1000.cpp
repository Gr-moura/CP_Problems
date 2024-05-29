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
    int x, y;
    cin >> x >> y;
    int a, b;
    cin >> a >> b;

    int menor = x < y ? abs(x) : abs(y);
    int total = abs(x) + abs(y);
    int dol = 0;

    if (b <= 2 * a && abs(x + y) > abs(x - y))
    {
        dol = b * menor;
        total -= 2 * menor;
    }

    dol += total * a;

    cout << dol << endl;
}

int32_t main()
{
    fast_io;
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
