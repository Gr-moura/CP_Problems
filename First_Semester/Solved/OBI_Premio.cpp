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

// paes = 1, doce = 2, bolo = 3
//  se a soma for maior ou igul a 150, recebe um bolo
//  maior ou igual a 120 recebe um doce
//  maior ou igual a 100 recebe um pao

void solve()
{
    int p, d, b;
    cin >> p >> d >> b;
    int pontos = p + 2 * d + 3 * b;

    if (pontos >= 150)
    {
        cout << "B\n";
        return;
    }
    if (pontos >= 120)
    {
        cout << "D\n";
        return;
    }
    if (pontos >= 100)
    {
        cout << "P\n";
        return;
    }
    cout << "N\n";
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
