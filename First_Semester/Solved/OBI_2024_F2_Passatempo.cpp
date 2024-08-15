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
    map<string, pii> val;

    int l, c;
    cin >> l >> c;

    set<string> variaveis;

    vi somas(l + c);
    int index = 0;

    string mat[l][c];

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
            variaveis.insert(mat[i][j]);
        }

        cin >> somas[index++];
    }

    for (int i = 0; i < c; i++)
        cin >> somas[index++];

    int n = sz(variaveis);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            set<string> desconhecidas;
            map<string, int> conhecidas;

            pair<string, int> nova;

            for (int k = 0; k < c; k++)
            {
                if (val[mat[j][k]].f == 0)
                {
                    desconhecidas.insert(mat[j][k]);
                    nova.f = mat[j][k];
                    nova.s++;
                }

                else
                {
                    conhecidas[mat[j][k]]++;
                }

                if (desconhecidas.size() == 2)
                    break;
            }

            if (desconhecidas.size() == 1)
            {
                int valor = somas[j];
                for (auto p : conhecidas)
                {
                    valor -= val[p.f].s * p.s;
                }

                val[nova.f] = {LINF, valor / nova.s};
            }
        }

        for (int j = 0; j < c; j++)
        {
            set<string> desconhecidas;
            map<string, int> conhecidas;

            pair<string, int> nova;

            for (int k = 0; k < l; k++)
            {
                if (val[mat[k][j]].f == 0)
                {
                    desconhecidas.insert(mat[k][j]);
                    nova.f = mat[k][j];
                    nova.s++;
                }

                else
                {
                    conhecidas[mat[k][j]]++;
                }

                if (desconhecidas.size() == 2)
                    break;
            }

            if (desconhecidas.size() == 1)
            {
                int valor = somas[l + j];
                for (auto p : conhecidas)
                {
                    valor -= val[p.f].s * p.s;
                }

                val[nova.f] = {LINF, valor / nova.s};
            }
        }
    }

    for (auto s : variaveis)
    {
        cout << s << " " << val[s].s << endl;
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
