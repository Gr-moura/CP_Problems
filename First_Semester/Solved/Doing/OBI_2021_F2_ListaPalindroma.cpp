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

int eh_pal(vi &nums, int n)
{
    for (int i = 0; i < (n / 2 + 1); i++)
    {
        if (nums[i] != nums[n - 1 - i])
            return 0;
    }

    return 1;
}

void solve()
{
    int n;
    cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (eh_pal(nums, n))
    {
        cout << 0;
        return;
    }

    int ans = 0;
    for (int i = 0; i < (n / 2 + 1);)
    {
        if (nums[i] == nums[n - 1 - i])
        {
            i++;
            continue;
        }

        int somaL = nums[i], somaR = nums[n - 1 - i];
        int l = i, r = n - 1 - i;

        while (somaL != somaR)
        {
            if (somaL < somaR)
            {
                l++;
                somaL += nums[l];
                ans++;
            }
            else if (somaL > somaR)
            {
                r--;
                somaR += nums[r];
                ans++;
            }
        }

        if (r >= l)
            break;
    }

    cout << ans;
}
// 10 60 20 40 40 10

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

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
