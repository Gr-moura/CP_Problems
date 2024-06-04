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

void solve()
{
    int cordas;
    int pedacos;
    cin >> cordas >> pedacos;

    double menor = INF;
    double maxdiff = 1e-7;
    vector<double> tam(cordas);
    for (int i = 0; i < cordas; i++)
    {
        cin >> tam[i];
        if (tam[i] < menor)
            menor = tam[i];
    }

    double diff = 1;
    double ultimo = 0;
    double hi = menor, lo = 1;
    while (diff - maxdiff > 0)
    {
        diff = (lo + hi) / 2;
        int feitos = 0;
        for (int i = 0; i < cordas; i++)
        {
            int res = tam[i] / diff;
            feitos += (int)res;
        }

        if (feitos >= pedacos)
            lo = diff;
        else
            hi = diff;

        if (ultimo == diff)
            break;
        ultimo = diff;
    }
    cout << diff << endl;
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
