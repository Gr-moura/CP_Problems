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
    vector<int> v(3);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    int temp, a = v[0], b = v[1], c = v[2];

    int maior = -1;

    for (int i = n / a; i >= 0; i--)
    {
        for (int j = 0; j <= n / b; j++)
        {
            int k = (n - a * i - b * j) / c;

            if (k >= 0 && a * i + b * j + c * k == n)
            {
                if ((i + j + k) > maior)
                    maior = i + j + k;
            }
        }
    }

    cout << maior;
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
