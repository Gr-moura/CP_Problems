#include <algorithm>
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
vector<long long> primos;

void solve()
{
    int a;
    cin >> a;
    int l = 2, r = 1e6;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid * mid >= a)
            r = mid;
        else
            l = mid + 1;
    }

    if (l * l == a)
    {
        if (binary_search(all(primos), l))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);
    primos.pb(2);

    int add = 0;
    for (int i = 3; i < 1e6; i += 2)
    {
        add = 1;
        for (auto j : primos)
        {
            if (i % j == 0)
            {
                add = 0;
                break;
            }
            if (j * j > i)
                break;
        }
        if (add)
        {
            primos.pb(i);
        }
    }

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
