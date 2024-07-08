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
const int MOD = 998244353;

void solve()
{
    int n1, ans = 1;
    cin >> n1;

    vector<int> el(n1);

    unordered_map<int, int> a;
    unordered_map<int, int> b;

    for (int i = 0; i < n1; i++)
    {
        cin >> el[i];
    }

    for (int i = 0; i < n1; i++)
    {
        int temp;
        cin >> temp;

        a[el[i]] = temp;
    }

    el.clear();

    int n2;
    cin >> n2;

    vector<int> el2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> el2[i];

        if (!a[el2[i]])
        {
            cout << 0 << endl;
            return;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        int temp;
        cin >> temp;

        b[el2[i]] = temp;

        if (a[el2[i]] < b[el2[i]])
        {
            cout << 0 << endl;
            return;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        if (a[el[i]] - b[el[i]] > 0)
        {
            ans *= 2;
            ans %= MOD;
        }
    }

    ans %= MOD;
    cout << ans;
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
