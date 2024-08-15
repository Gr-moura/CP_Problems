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
    vi difs;
    int ans = 0;

    int n;
    cin >> n;

    vi nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int anterior = nums[0];

    for (int i = 1; i < n; i++)
    {
        int atual = nums[i];

        if (atual < anterior)
        {
            difs.pb(anterior - atual);
            continue;
        }

        anterior = atual;
    }

    sort(all(difs));

    int soma = 0;

    int sz = difs.size();

    for (int i = 0; i < sz; i++)
    {
        difs[i] -= soma;
        ans += (sz - i + 1) * difs[i];
        soma += difs[i];
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
