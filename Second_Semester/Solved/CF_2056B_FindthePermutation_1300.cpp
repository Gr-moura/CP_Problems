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

    vi p(n);
    vi qtA(n, 0);
    vi qtD(n, 0);
    vector<string> mat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    for (int i = 0; i < n; i++)
    {
        int qt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j] == '1')
                qt++;
        }
        qtA[i] = qt;
        //       p[n - 1 - qt] = i + 1;
        //     cout << i + 1 << " : ";
        //   dbg(qt);
    }

    for (int i = 0; i < n; i++)
    {
        int qt = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (mat[i][j] == '0')
                qt++;
        }
        qtD[i] = qt;
        //       p[n - 1 - qt] = i + 1;
        //     cout << i + 1 << " : ";
        //   dbg(qt);
    }

    for (int i = 0; i < n; i++)
    {
        p[qtA[i] + qtD[i]] = i + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << p[i] << " ";
    }

    cout << endl;
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
