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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool cmp(ii a, ii b)
{
    if (a.s != b.s)
        return a.s < b.s;
    else
        return a.f < b.f;
}

void solve()
{
    int orders;
    cin >> orders;
    vector<ii> periodos;

    for (int i = 0; i < orders; i++)
    {
        int inicio, fim;
        cin >> inicio >> fim;

        periodos.pb({inicio, fim});
    }

    sort(all(periodos), cmp);

    ii atual = periodos[0];
    int ans = 1;

    for (int i = 1; i < orders; i++)
    {
        if (periodos[i].f > atual.s)
        {
            atual = periodos[i];
            ans++;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
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
