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
    int sa, sb;
    cin >> sa >> sb;

    vi a(sa), b(sb), c(sa + sb);
    for (int i = 0; i < sa; i++)
        cin >> a[i];
    for (int i = 0; i < sb; i++)
        cin >> b[i];

    int ia = 0, ib = 0;
    for (int i = 0; i < sa + sb; i++)
    {
        if (ia < sa && ib < sb)
        {
            if (a[ia] <= b[ib])
            {
                c[i] = a[ia];
                ia++;
            }
            else
            {
                c[i] = b[ib];
                ib++;
            }
        }

        else if (ia == sa)
        {
            c[i] = b[ib];
            ib++;
        }
        else if (ib == sb)
        {
            c[i] = a[ia];
            ia++;
        }
    }

    for (auto i : c)
        cout << i << " ";
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
