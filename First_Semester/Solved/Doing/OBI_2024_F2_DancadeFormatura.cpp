#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0)

#define int long long
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define endl '\n'

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int linhas, colunas, passos;
    cin >> linhas >> colunas >> passos;

    vector<vector<int>> baile(linhas, vector<int>(colunas));

    vector<int> Linhas(linhas);
    vector<int> Colunas(colunas);

    for (int i = 0; i < linhas; i++)
        Linhas[i] = i;

    for (int i = 0; i < linhas; i++)
        Colunas[i] = i;

    int a = 1;

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            baile[i][j] = a++;

    int temp, a1, a2;

    for (int i = 0; i < passos; i++)
    {
        char comando;

        cin >> comando;
        cin >> a1 >> a2;

        a1--, a2--;

        if (comando == 'C')
        {
            temp = Colunas[a1];
            Colunas[a1] = Colunas[a2];
            Colunas[a2] = temp;
            continue;
        }

        temp = Linhas[a1];
        Linhas[a1] = Linhas[a2];
        Linhas[a2] = temp;
    }

    for (auto i : Linhas)
    {
        for (auto j : Colunas)
            cout << baile[i][j] << " ";

        cout << endl;
    }
}

int32_t main()
{
    fast_io;
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
        solve();

    return 0;
}
