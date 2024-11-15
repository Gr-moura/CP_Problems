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
    int n, m, v;
    cin >> n >> m >> v;

    vi tastiness(n);
    for (auto &i : tastiness)
        cin >> i;

    vi prefixo(n + 1, 0);
    vi sufixo(n + 1, 0);
    int atual = 0;

    for (int i = 0; i < n; i++)
    {
        atual += tastiness[i];
        if (atual >= v)
        {
            if (i - 1 >= 0)
                prefixo[i + 1] = prefixo[i] + 1;
            else
                prefixo[i + 1] = 1;

            atual = 0;
            continue;
        }

        prefixo[i] = prefixo[i - 1];
    }

    atual = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        atual += tastiness[i];
        if (atual >= v)
        {
            if (i + 1 < n)
                sufixo[i] = sufixo[i + 1] + 1;
            else
                sufixo[i] = 1;

            atual = 0;
            continue;
        }

        if (i + 1 < n)
            sufixo[i] = sufixo[i + 1];
    }

    int l = 0;
    r = 1;
    while (1)
    {
    }
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
