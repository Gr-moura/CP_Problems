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

    vector<pair<int, bool>> ev;
    int ADD = 0, RMV = 1;

    int anterior;
    for (int i = 0; i < n; i++)
    {
        int atual;
        cin >> atual;

        if (i == 0)
        {
            ev.pb({atual, ADD});
            anterior = atual;
            continue;
        }

        else
        {
            if (atual > anterior)
            {
                ev.pb({atual, ADD});
                ev.pb({anterior, RMV});
            }
        }

        anterior = atual;
    }

    sort(all(ev), greater<>());

    int cnt = 0, maxcnt = -1;

    for (auto p : ev)
    {
        bool tipo = p.second;

        if (tipo == ADD)
            cnt++;
        else
            cnt--;
        cout << "Altura: " << p.f << " - - - Tipo: " << p.s << endl;

        maxcnt = max(cnt, maxcnt);
    }

    cout << maxcnt + 1;
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
