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
    int n, k;
    cin >> n >> k;

    vi boardV(n);
    map<int, int> boardM;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        boardV[i] = temp;
        boardM[temp]++;
    }

    sort(all(boardV));

    if (boardV[0] + boardV[1] > k || boardV[n - 1] + boardV[n - 2] < k)
    {
        cout << 0 << endl;
        return;
    }

    int comPar = 0;

    for (int l = 0, r = n - 1; l < r;)
    {
        if (boardV[l] + boardV[r] > k)
            r--;
        else if (boardV[l] + boardV[r] < k)
            l++;
        else
        {
            comPar += 1;
            l++, r--;
        }
    }

    cout << comPar << endl;
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
