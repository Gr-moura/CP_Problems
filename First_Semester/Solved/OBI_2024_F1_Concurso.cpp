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
    int part, aprov;
    cin >> part >> aprov;
    vi notas(part);
    for (int i = 0; i < part; i++)
        cin >> notas[i];
    sort(all(notas));

    cout << notas[notas.size() - aprov];
}

int32_t main()
{
    _ int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
