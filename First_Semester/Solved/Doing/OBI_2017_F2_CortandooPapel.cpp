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

    vi nums(n);
    vi snums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    snums = nums;
    sort(all(snums));

    int acc = 700;

    int ans = -1;

    int l = n / 2 - acc > 0 ? n / 2 - acc : 0;
    int r = n / 2 + acc < n - 1 ? n / 2 + acc : n - 1;

    int atual;
    for (int i = l; i <= r; i++)
    {
        atual = snums[i];
        int teste_atual = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (nums[j] > atual && nums[j + 1] <= atual)
                teste_atual++;
        }
        if (nums[n - 1] > atual && nums[n - 2] <= atual)
            teste_atual++;

        if (ans == -1 or teste_atual > ans)
            ans = teste_atual;
    }

    cout << ans + 1;
}

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
