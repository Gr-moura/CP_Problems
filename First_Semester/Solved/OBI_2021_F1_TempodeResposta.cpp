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
    int t;
    cin >> t;

    set<int> nomes;
    map<int, int> vacuo;
    map<int, int> tempo;
    for (int i = 0; i < t; i++)
    {
        int add = 1;
        char comando;
        cin >> comando;

        int amigo;
        cin >> amigo;

        if (comando != 'T')
            nomes.insert(amigo);

        else
            add = amigo - 1;

        for (auto nome : nomes)
        {
            if (vacuo[nome] == 1)
            {
                tempo[nome] += add;
            }
        }

        if (comando == 'R')
        {
            vacuo[amigo]++;
        }
        else if (comando == 'E')
        {
            vacuo[amigo]--;
        }
    }

    for (auto i : nomes)
    {
        if (vacuo[i] == 0)
            cout << i << " " << tempo[i] << endl;
        else
            cout << i << " -1" << endl;
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
