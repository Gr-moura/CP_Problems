#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0);
#define int long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define lb(v, x) (lower_bound(all(v), x) - v.begin())
#define ub(v, x) (upper_bound(all(v), x) - v.begin())
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl
const int INF = 0x3f3f3f3f;

typedef vector<int> vi;
typedef pair<int, int> pii;

void solve()
{
    int n, estado;
    cin >> n >> estado;

    vector<pii> possibilidades = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
    vector<string> tab(n);
    vector<vector<int>> vizinhos(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        cin >> tab[i];

    for (int est = 0; est < estado; est++)
    {

        // Ver vizinhos vivos e mortos
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vizinhos[i][j] = 0;
                for (auto p : possibilidades)
                {
                    if ((i + p.f >= 0 && i + p.f < n) && (j + p.s >= 0 && j + p.s < n))
                    {
                        if (tab[i + p.f][j + p.s] == '1')
                        {
                            vizinhos[i][j]++;
                        }
                    }
                }
            }
        }

        // Situacao atual de acordo com vizinhos vivos e mortos
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tab[i][j] == '0')
                {
                    if (vizinhos[i][j] == 3)
                        tab[i][j] = '1';
                }

                else if (tab[i][j] == '1')
                {
                    if (vizinhos[i][j] < 2)
                        tab[i][j] = '0';
                    else if (vizinhos[i][j] > 3)
                        tab[i][j] = '0';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << endl;
    }
}

int32_t main()
{
    _ int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
