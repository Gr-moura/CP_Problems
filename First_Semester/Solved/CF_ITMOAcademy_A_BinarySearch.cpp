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
#define lb(vect, x) lower_bound(all(vect), x) - vect.begin()
#define ub(vect, x) upper_bound(all(vect), x) - vect.begin();

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int achou, len, queries;
    cin >> len >> queries;

    vector<int> nums(len);
    for (int i = 0; i < len; i++)
        cin >> nums[i];

    for (int i = 0; i < queries; i++)
    {
        int buscar;
        cin >> buscar;

        int lo = 0, hi = len, achou = 0;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;

            if (nums[mid] > buscar)
                hi = mid;

            else if (nums[mid] < buscar)
                lo = mid + 1;

            else
            {
                cout << "YES\n";
                achou = 1;
                break;
            }
        }

        if (!achou)
            cout << "NO\n";
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
    //    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
