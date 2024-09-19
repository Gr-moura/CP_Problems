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

bool compare(pii a, pii b)
{
    if (a.s < b.s)
    {
        return 1;
    }

    return 0;
}

void solve()
{
    int ans = 0;

    int n;
    cin >> n;

    set<pii> pos;

    for (int i = 0; i < n; i++)
    {
        pii temp;
        cin >> temp.f >> temp.s;

        pos.insert({temp.f, temp.s});
    }

    int antX = -1;

    for (auto p : pos)
    {
        // Quantos pares com mesmo X * (Total de pontos - 2)
        if (antX == p.f)
        {
            ans += n - 2;
        }

        // Existe um ponto x-1 com altura trocada e
        // um ponto posterior x + 1 com altura trocada
        if (pos.count({p.f - 1, !p.s}) && pos.count({p.f + 1, !p.s}))
            ans++;

        antX = p.f;
    }

    cout << ans << endl;
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
