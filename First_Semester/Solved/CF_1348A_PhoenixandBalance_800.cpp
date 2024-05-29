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

void solve(vector<int> coins)
{
    int quantidade;
    cin >> quantidade;

    if (quantidade == 2)
    {
        cout << "2\n";
        return;
    }

    else
    {
        int somaA = 0, somaB = 0;
        somaA += coins[quantidade] + coins[1];
        for (int i = quantidade - 1; i >= quantidade / 2; i--)
        {
            somaB += coins[i];
        }

        for (int i = 2; i < quantidade / 2; i++)
            somaA += coins[i];

        cout << abs(somaA - somaB) << endl;
    }
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin >> t;
    vector<int> coins(31);
    coins[0] = 1;
    for (int i = 1; i < 31; i++)
        coins[i] = coins[i - 1] * 2;

    for (int i = 1; i <= t; i++)
    {
        solve(coins);

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
