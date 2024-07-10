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
    int sz;
    cin >> sz;

    vector<int> ans(sz);
    vector<int> nums(sz);

    for (int i = 0; i < sz; i++)
        cin >> nums[sz - i - 1];

    if (nums[0] == 1)
    {
        cout << "NO\n";
        return;
    }

    int add = 0;
    for (int i = 0; i < sz; i++)
    {

        if (nums[i] == 1)
        {
            add++;
            ans[i] = 0;

            if (i + 1 == sz)
                ans[i] = add;

            if (i + 1 < sz && nums[i + 1] == 0)
            {
                ans[i] = add;
                add = 0;
            }
        }

        else
        {
            ans[i] = 0;
            add = 0;
        }
    }

    cout << "YES\n";

    for (int i = 0; i < sz; i++)
    {
        cout << ans[i];
        cout << " ";
    }

    cout << endl;
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
