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
#define lb(vect, x) lower_bound(all(vect), x) - vect.begin()
#define ub(vect, x) upper_bound(all(vect), x) - vect.begin()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;
vi v(MAX);

bool ehpossivel(int tirar, int len, int indmaior)
{
    for (int i = 1; i < len - tirar - 1; i++)
    {
        if (i <= indmaior)
        {
            if (v[i] < v[i - 1])
                return 0;
        }

        if (i >= indmaior)
            if (v[i] < v[i + 1])
                return 0;
    }
    return 1;
}

void solve()
{
    int len;
    cin >> len;
    int maior = -LINF, indmaior;

    for (int i = 0; i < len; i++)
    {
        cin >> v[i];
        if (v[i] > maior)
        {
            maior = v[i];
            indmaior = i;
        }
    }

    int lo = 0, hi = MAX;
    while (lo < hi)
    {
        int tirar = (lo + hi) / 2;

        if (ehpossivel(tirar, len, indmaior))
            hi = tirar;
        else
            lo = tirar + 1;
    }
    cout << lo << endl;
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
