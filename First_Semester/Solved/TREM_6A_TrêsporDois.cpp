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
    int chocolates;
    cin >> chocolates;

    vector<int> precos(chocolates);

    for (int i = 0; i < chocolates; i++)
        cin >> precos[i];

    sort(all(precos), greater<>());
    int soma = 0;

    for (int i = 0; i < chocolates; i++)
    {

        if ((i + 1) % 3 != 0)
        {
            soma += precos[i];
        }
    }

    cout << soma << endl;
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
