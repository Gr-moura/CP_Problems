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

    string s;
    cin >> s;

    int p = -LINF;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'p')
        {
            if (p == -LINF)
                p = i;

            continue;
        }

        if (s[i] == 's')
        {
            if (i > p && p != -LINF)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    int us = -LINF;
    int pp = -LINF;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'p')
        {
            if (pp == -LINF)
                pp = i;
        }

        if (s[n - i - 1] == 's')
        {
            if (us == -LINF)
                us = n - i - 1;
        }
    }

    if (us != 0 && pp != n - 1 && (us != -LINF && pp != -LINF))
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
