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
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    string bar;
    cin >> bar;

    map<char, vector<int>> cartas;
    map<char, int> faltam;
    map<char, int> errou;

    string naipes = "CEUP";

    for (int i = 0; i < bar.size(); i += 3)
    {
        int numero = 10 * (bar[i] - '0');
        numero += bar[i + 1] - '0';

        char naipe = bar[i + 2];
        cartas[naipe].pb(numero);
    }

    for (auto c : naipes)
    {
        sort(all(cartas[c]));

        for (int i = 1; i <= 13; i++)
        {
            int atual = ub(cartas[c], i) - lb(cartas[c], i);

            if (atual == 0)
            {
                faltam[c]++;
            }

            if (atual > 1)
            {
                errou[c] = 1;
            }
        }
    }

    for (auto c : naipes)
    {
        if (errou[c] == 1)
            cout << "erro" << endl;
        else
            cout << faltam[c] << endl;
    }
    /*    for (auto i : cartas['C'])
        cout << i;
    cout << endl;

    for (auto i : cartas['E'])
        cout << i;
    cout << endl;

    for (auto i : cartas['U'])
        cout << i;
    cout << endl;

    for (auto i : cartas['P'])
        cout << i;
    cout << endl;
    */
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
