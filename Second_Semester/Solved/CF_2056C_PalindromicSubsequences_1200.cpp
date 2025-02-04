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

    string quinze = "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8 ";
    string nove = "7 3 3 7 5 3 7 7 3 ";

    if (n >= 15)
    {
        cout << quinze;
        n -= 15;
        for (int i = 0; i < n; i++)
        {
            cout << i + 16 << " ";
        }
        cout << endl;
        return;
    }

    if (n >= 9)
    {
        cout << nove;
        n -= 9;
        for (int i = 0; i < n; i++)
        {
            cout << i + 8 << " ";
        }
        cout << endl;
        return;
    }

    if (n == 8)
    {
        cout << "1 1 2 3 1 2 2 4 " << endl;
        return;
    }
    if (n == 7)
    {
        cout << "1 1 2 3 1 2 2 " << endl;
        return;
    }

    if (n == 6)
    {
        cout << "1 1 2 3 1 2 " << endl;
        return;
    }
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
