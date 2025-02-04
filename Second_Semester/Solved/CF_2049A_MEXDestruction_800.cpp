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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    bool todos0 = 1;
    int pdifzero = -LINF;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            todos0 = 0;
            pdifzero = i;
            break;
        }
    }

    if (todos0)
    {
        cout << 0 << endl;
        return;
    }
    int esq = -LINF;

    for (int i = pdifzero; i < n; i++)
    {
        if (nums[i] == 0)
        {
            esq = i;
            break;
        }
    }

    int pdifzerodir = -LINF;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] != 0)
        {
            pdifzerodir = i;
            break;
        }
    }

    for (int i = pdifzero; i < pdifzerodir; i++)
    {
        if (nums[i] == 0)
        {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
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
