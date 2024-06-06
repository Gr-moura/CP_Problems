
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
    int balloons, assistants;
    cin >> balloons >> assistants;

    vector<vector<int>> dados(assistants, vector<int>(3));
    for (int i = 0; i < assistants; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> dados[i][j];
        }
    }

    vector<pair<int, vector<int>>> periodos(assistants);
    for (int i = 0; i < assistants; i++)
    {
        // Ver o periodo em que se repete
        periodos[i].f = dados[i][0] * dados[i][1] + dados[i][2];

        // Ver quais os momentos em que um balao e produzido
        for (int j = 1; j <= dados[i][1]; j++)
        {
            periodos[i].s.pb(dados[i][0] * j);
        }
    }

    vector<int> pessoas(assistants);
    int lo = 0, hi = LINF;
    while (lo < hi)
    {
        int minutos = (lo + hi) / 2;
        int baloes = 0;

        for (int i = 0; i < assistants; i++)
        {
            int feitos = 0;
            int vezes = minutos / periodos[i].f;

            feitos += periodos[i].s.size() * vezes;
            int resto = minutos % periodos[i].f;

            for (auto k : periodos[i].s)
            {
                if (resto >= k)
                {
                    feitos++;
                }
            }

            pessoas[i] = feitos;
            baloes += feitos;
        }

        if (baloes >= balloons)
            hi = minutos;
        else
            lo = minutos + 1;
    }

    int test = 0;

    for (int i = 0; i < assistants; i++)
    {
        int feitos = 0;
        int vezes = lo / periodos[i].f;

        feitos += periodos[i].s.size() * vezes;
        int resto = lo % periodos[i].f;

        for (auto k : periodos[i].s)
        {
            if (resto >= k)
                feitos++;
        }

        pessoas[i] = feitos;
        test += feitos;
    }

    int tirar = test - balloons;

    for (int i = 0; i < assistants && tirar > 0; i++)
    {
        if (pessoas[i] != 0)
        {
            pessoas[i]--;
            tirar--;
        }
    }

    cout << hi << endl;
    for (auto i : pessoas)
        cout << i << " ";
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
    int t = 1;
    //   cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
