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

bool ehpossivel(int tirar, int len)
{
    for (int i = 0; i != 0;)
        ;
    return true;
}

void solve()
{
    int len;
    cin >> len;
    int original = len;

    for (int i = 0; i < len; i++)
        cin >> v[i];

    for (int fim = len - 2, inicio = 0; fim > 0; fim--, inicio++)
    {
        if (v[fim] < v[fim + 1] && v[fim] < v[fim - 1])
        {
            len = fim;
            inicio = -1;
        }
    }

    cout << original - len << endl;

    /*int lo = 0, hi = MAX;
    while (lo < hi)
    {
        int tirar = (lo + hi) / 2;

        if (ehpossivel(tirar, len))
            hi = tirar;
        else
            lo = tirar + 1;
    }*/
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
