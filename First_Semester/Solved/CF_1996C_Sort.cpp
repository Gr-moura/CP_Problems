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
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> preA(n, vector<int>(26, 0));
    vector<vector<int>> preB(n, vector<int>(26, 0));

    preA[0][a[0] - 'a']++;
    preB[0][b[0] - 'a'] += 43;

    for (int i = 1; i < n; i++)
    {
        preA[i] = preA[i - 1];
        preA[i][a[i] - 'a']++;

        preB[i] = preB[i - 1];
        preB[i][b[i] - 'a']++;
    }

    for (int i = 0; i < q; i++)
    {
        vector<int> lA(26, 0);
        vector<int> lB(26, 0);

        int l, r, ans = 0;
        cin >> l >> r;
        l--, r--;

        if (l == 0)
        {
            lA = preA[r];
            lB = preB[r];
        }
        else

            for (int j = 0; j < 26; j++)
            {
                lA[j] = preA[r][j] - preA[l - 1][j];
                lB[j] = preB[r][j] - preB[l - 1][j];
            }

        for (int j = 0; j < 26; j++)
        {
            ans += abs(lA[j] - lB[j]);
        }
        cout << ans / 2 << endl;
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
