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

int ehprimo(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 1;
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    if (n <= 4)
    {
        cout << -1 << endl;
        return;
    }

    if (n == 5)
    {
        cout << "1 3 5 4 2" << endl;
        return;
    }

    int mp = 0;
    int mi = 0;

    if (n % 2 == 0)
    {
        mp = n;
        mi = n - 1;
    }
    else
    {
        mi = n;
        mp = n - 1;
    }

    int imparAtual = mi;
    while (imparAtual >= 1)
    {
        if (ehprimo(mp + imparAtual))
        {
            for (int i = 1; i <= mi; i += 2)
            {
                if (i != imparAtual)
                {
                    cout << i << " ";
                }
            }
            cout << imparAtual << " ";

            for (int i = mp; i >= 2; i -= 2)
            {
                cout << i << " ";
            }

            return;
        }

        imparAtual -= 2;
    }
    cout << "-1\n";
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
