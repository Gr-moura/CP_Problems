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

int fact(int num)
{
    int ans = 1;
    for (int i = 2; i <= num; i++)
        ans *= i;

    return ans;
}

void solve()
{
    int t;
    cin >> t;

    int soma = 0, add;
    for (int i = 0; i < t; i++)
    {
        cin >> add;
        add = fact(add);
        soma += add;
    }

    cout << soma;
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
