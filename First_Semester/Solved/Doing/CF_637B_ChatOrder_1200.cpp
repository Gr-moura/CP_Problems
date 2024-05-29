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
    int nomes, tam = 0;
    cin >> nomes;
    vector<string> fila;
    map<string, int> mp;

    for (int i = 0; i < nomes; i++)
    {
        string a;
        cin >> a;
        if (mp[a] == 0)
            tam++;
        mp[a] = 1;
        fila.pb(a);
    }

    vector<string> resposta;
    for (int i = fila.size() - 1, vezes = 0; vezes < tam; i--)
    {
        if (mp[fila[i]] == 1)
        {
            cout << fila[i] << endl;
            mp[fila[i]] = 2;
            vezes++;
        }
    }
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
