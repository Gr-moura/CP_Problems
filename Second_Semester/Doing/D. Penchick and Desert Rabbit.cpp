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

    vi nums(n);
    for (int &i : nums)
        cin >> i;

    vi minimo(n, 0);
    vi maximo(n, 0);

    minimo[n - 1] = nums[n - 1];
    maximo[0] = nums[0];

    for (int i = n - 2; i >= 0; i--)
    {
        int atual = nums[i];
        if (atual < minimo[i + 1])
            minimo[i] = atual;

        else
            minimo[i] = minimo[i + 1];
    }

    for (int i = 1; i < n; i++)
    {
        int atual = nums[i];
        if (atual > maximo[i - 1])
            maximo[i] = atual;

        else
            maximo[i] = maximo[i - 1];
    }

    for (int k = 0; k < 1e3; k++)
        for (int i = 0; i < n; i++)
        {
            if (i - 1 > 0 && minimo[i - 1] > minimo[i])
            {
                minimo[i] = minimo[i - 1];
                // for (int i : minimo)
                //     cout << i << " ";
                // cout << endl;
            }
            if (i + 1 < n && minimo[i + 1] > minimo[i])
            {
                for (int j = 0; j <= i; j++)
                    minimo[j] = maximo[i];
                // for (int i : minimo)
                //     cout << i << " ";
                // cout << endl;
                break;
            }

            if (i + 1 < n && minimo[i + 1] < minimo[i])
            {

                minimo[i + 1] = minimo[i];
                // for (int i : minimo)
                //     cout << i << " ";
                // cout << endl;
                break;
            }
        }
    for (int i : minimo)
        cout << i;
    cout << endl;

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
