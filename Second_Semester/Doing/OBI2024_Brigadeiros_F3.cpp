#include "Headers.h"
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

/* menor tempo necessário para comer b brigadeiros,
 * considerando apenas o prefixo [1..p] dos pratos e
 * [1..a] dos amigos do grupo.
 *
 * 1 amigo 1 prato 1 brigadeiro
 * 2 amigos 1 prato 5 brigadeiros
 * */

void solve()
{
    int nPratos, nAmigos, segundos;
    cin >> nPratos >> nAmigos >> segundos;

    vi qtBrigs(nPratos);
    for (int &i : qtBrigs)
        cin >> i;

    vi posicoes;
    for (int i = 1; i <= nAmigos; i++)
    {
        int temp;
        cin >> temp;

        if (temp)
            posicoes.pb(i);
    }

    int dp[302][302][300 * 9 + 2];
    memset(dp, 0, sizeof dp);

    for (int a = 1; a < nPratos; a++)
    {
        for (int b = 1; b <= nAmigos; b++)
        {
            for (int c = 1; c <= nAmigos * 9; c++)
            {
                if (c - qtBrigs[a] >= 0)
                    dp[a][b][c] = min(dp[a - 1][b - 1][c - qtBrigs[posicoes[a] - 1]] + abs(a - b), dp[a - 1][b][c]);
            }
        }
    }
    int ans = -1;
    for (int C = 0; C < nAmigos * 9 - 1; C++)
    {
        if (dp[nPratos][nAmigos][C] <= segundos)
            ans = max(ans, C);
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
