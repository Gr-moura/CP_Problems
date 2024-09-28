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
    // The operation strategy works by iteratively narrowing the range of all
    // elements. Initially, the range of all elements is between [0,2^30].

    // Starting from 𝑥 = 2^29, we use each power of 2 as 𝑥, reducing
    // the exponent by one each time (i.e., 2^29, 2^28, …, 2^0).
    // After each operation, the range of all elements is halved,
    // narrowed down to [0, 𝑥].

    // Continuing this process, after 30 operations, all elements will
    // become 0 or 1 .If all elements are 1 after 30 operations,
    // perform one last operation with 𝑥 = 1 to turn all 1s into 0s.

    vi pot2(30, 1);

    for (int i = 1; i < 30; i++)
        pot2[i] = pot2[i - 1] * 2;

    int n;
    cin >> n;

    vi nums(n);
    int par = 0;
    int impar = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] % 2 == 0)
            par = 1;

        else
            impar = 1;
    }

    if (par && impar)
    {
        cout << -1 << endl;
        return;
    }

    sort(all(nums));

    vi ans;

    for (int i = 29; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            nums[j] = abs(nums[j] - pot2[i]);
        }

        ans.pb(pot2[i]);
    }

    sort(all(nums));

    if (nums.back())
        ans.pb(1);

    cout << sz(ans) << endl;

    for (int i = 0; i < sz(ans); i++)
        cout << ans[i] << ' ';

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
