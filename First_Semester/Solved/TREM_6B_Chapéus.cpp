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

void solve()
{
    int qt;
    cin >> qt;

    queue<int> chapeus;

    for (int i = 0; i < qt; i++)
    {
        int a;
        cin >> a;
        chapeus.push(a);
    }

    string felicidade;
    cin >> felicidade;
    vector<int> posicoes;

    for (int i = 0; i < qt; i++)
    {
        if (felicidade[i] == '1')
        {
            posicoes.pb(i + 1);
        }
    }

    int buscar = -1;
    if (posicoes.size() == 0)
    {
        cout << "YES\n";
        return;
    }

    buscar = posicoes[0];
    int pos_atual = 0;

    for (int i = 0; i < qt; i++)
    {
        if (felicidade[i] == '1')

            if (chapeus.front() == i + 1)
            {
                chapeus.pop();
                pos_atual++;
                buscar = posicoes[pos_atual];
            }
            else
            {
                cout << "NO\n";
                return;
            }

        else
        {
            if (chapeus.front() != buscar && chapeus.front() != i + 1)
                chapeus.pop();
        }
    }

    cout << "YES\n";
}

int32_t main()
{
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
