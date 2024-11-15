#include "Headers.h"
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
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int n;
    cin >> n;

    vi interesses;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        interesses.pb(temp);
    }

    for (int i = 1; i < n / 2; i++)
    {
        int atual = interesses[i];
        int anterior = i > 0 ? interesses[i - 1] : -1;
        int posterior = i < n ? interesses[i + 1] : -1;

        if (atual == anterior)
        {
            int temp = interesses[n - i - 1];
            interesses[n - i - 1] = interesses[i];
            interesses[i] = temp;
            continue;
        }

        else if (interesses[n - i - 1] == interesses[n - i])
            swap(interesses[i], interesses[n - i - 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (interesses[i] == interesses[i + 1])
            ans++;
    }
    cout << ans << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

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
