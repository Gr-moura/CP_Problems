#ifdef ONPC
#include "Headers.h"
#endif

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
    int n, x;
    cin >> n >> x;

    int atual = 0;

    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp < n)
        {
            freq[temp]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[atual] == 0)
        {
            cout << atual << endl;
            return;
        }

        if (freq[atual] > 1)
        {
            if (x + atual < n)
                // Como você mexe somente o último por vez, não
                // existe o risco de você retirar uma opção não-ótima
                freq[x + atual] += freq[atual] - 1;
        }

        atual++;
    }
    cout << atual << endl;
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
