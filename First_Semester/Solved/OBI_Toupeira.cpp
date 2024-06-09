#include <algorithm>
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
    vector<pii> pares;
    int vezes;
    int tam, possiveis = 0;
    vi caminho;
    while (1)
    {
        string ss;
        getline(cin, ss);
        if (ss.size() == 1)
        {
            vezes = ss[0] - '0';
            break;
        }
        if (ss.size() == 3)
        {
            pares.pb({ss[0] - '0', ss[2] - '0'});
        }
    }

    for (int i = 0; i < vezes; i++)
    {
        cin >> tam;
        caminho.clear();
        int pos = 0;

        for (int j = 0; j < tam; j++)
        {
            int a;
            cin >> a;
            caminho.pb(a);
        }

        int ultimo = caminho[0];
        for (int j = 1; j < tam; j++)
        {
            if (count(all(pares), make_pair(caminho[j], ultimo)) or count(all(pares), make_pair(ultimo, caminho[j])))
            {
                pos++;
                ultimo = caminho[j];
                continue;
            }
            else // fazer mada
                break;
            ultimo = caminho[j];
        }
        if (pos == tam - 1)
            possiveis++;
    }
    cout << possiveis << endl;
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
