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
const int INF = 0x3f3f3f3f;

typedef vector<int> vi;
typedef pair<int, int> pii;

void solve()
{
    string placa;
    cin >> placa;
    if (placa.size() == 8)
    {
        if ((placa[0] - 'A' >= 0 && placa[0] - 'A' < 26) && (placa[1] - 'A' >= 0 && placa[1] - 'A' < 26) &&
            (placa[2] - 'A' >= 0 && placa[2] - 'A' < 26) && (placa[3] == '-') &&
            (placa[4] - '0' >= 0 && placa[4] - '0' < 10) && (placa[5] - '0' >= 0 && placa[5] - '0' < 10) &&
            (placa[6] - '0' >= 0 && placa[6] - '0' < 10) && (placa[7] - '0' >= 0 && placa[7] - '0' < 10))
        {
            cout << 1;
        }
        else
            cout << 0;
    }
    else if (placa.size() == 7)
    {
        if ((placa[0] - 'A' >= 0 && placa[0] - 'A' < 26) && (placa[1] - 'A' >= 0 && placa[1] - 'A' < 26) &&
            (placa[2] - 'A' >= 0 && placa[2] - 'A' < 26) && (placa[3] - '0' >= 0 && placa[3] - '0' < 10) &&
            (placa[4] - 'A' >= 0 && placa[4] - 'A' < 26) && (placa[5] - '0' >= 0 && placa[5] - '0' < 10) &&
            (placa[6] - '0' >= 0 && placa[6] - '0' < 10))
        {
            cout << 2;
        }
        else
            cout << 0;
    }

    else
        cout << 0;
}

int32_t main()
{
    _ int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
