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
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    int ss = t1 + t2;
    int ans = 0;
    int inicio, fim;
    cin >> inicio >> fim;
    ans += (fim - inicio) * p1;
    int last = fim;
    for (int i = 1; i < n; i++)
    {
        cin >> inicio >> fim;
        ans += (fim - inicio) * p1;
        if (inicio - last <= t1)
        {
            ans += (inicio - last) * p1;
        }
        else if (inicio - last <= ss)
        {
            ans += t1 * p1 + (inicio - last - t1) * p2;
        }
        else
        {
            ans += t1 * p1 + t2 * p2 + (inicio - last - ss) * p3;
        }
        last = fim;
    }

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
