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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Com dois movimentos a rainha consegue chegar a qualquer casa do jogo
// Dessa forma, basta olhar se o destino é a mesma peça ( return 0 )
// Ou se é um dos locais no alcance da rainha ( return 1 )

void solve()
{
    vector<ii> possibilidades = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Olhar se é o mesmo lugar
    if (x2 == x1 && y2 == y1)
    {
        cout << "0";
        return;
    }

    // Olhar se está na mesma linha ou na mesma coluna
    if (x2 - x1 == 0 || y2 - y1 == 0)
    {
        cout << "1";
        return;
    }

    // Olhar se está na mesma diagonal
    for (int add = 1; add < 8; add++)
    {
        for (auto p : possibilidades)
        {
            if (x2 - add * p.f == x1 && y2 - add * p.s == y1)
            {
                cout << "1";
                return;
            }
        }
    }

    cout << "2";
}

int32_t main()
{
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
