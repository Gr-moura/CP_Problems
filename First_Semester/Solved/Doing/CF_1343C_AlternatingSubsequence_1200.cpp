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
    int size;
    cin >> size;

    vector<int> elementos;

    int add;
    cin >> add;
    elementos.pb(add);

    if (size == 1)
    {
        cout << add << endl;
        return;
    }

    int somar = add;

    int buscar = elementos[0] > 0 ? -1 : 1;
    int soma = 0;

    for (int i = 1; i < size; i++)
    {
        cin >> add;
        elementos.pb(add);

        if (add * buscar > 0)
        {
            buscar *= -1;
            soma += somar;
            somar = add;
        }

        else
        {
            if (add > somar)
                somar = add;
        }
    }

    soma += somar;
    cout << soma << endl;
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
