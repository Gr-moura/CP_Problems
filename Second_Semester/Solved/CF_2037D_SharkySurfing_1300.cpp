#include "Headers.h"
#include <bits/stdc++.h>
#include <queue>
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
    int n, m, l;
    cin >> n >> m >> l;

    vector<pii> hurdles(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        hurdles[i] = {a, b - a + 1};
    }

    vector<pii> pus(m);
    for (int i = 0; i < m; i++)
    {
        int pos, v;
        cin >> pos >> v;

        pus[i] = {pos, v};
    }

    int puAtual = 0;
    int poder = 0;
    int qt = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        // Adicionamos todos os pu antes do hurdle atual em uma lista
        while (puAtual < m && pus[puAtual].f < hurdles[i].f)
        {
            pq.push(pus[puAtual].s);
            puAtual++;
        }

        // Se o nosso poder for menor do que o necessario para pularmos
        // pegamos o maior poder disponivel
        while (poder < hurdles[i].s)
        {
            if (pq.empty())
            {
                cout << "-1\n";
                return;
            }

            poder += pq.top();
            qt++;
            pq.pop();
        }
    }

    cout << qt << endl;
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
