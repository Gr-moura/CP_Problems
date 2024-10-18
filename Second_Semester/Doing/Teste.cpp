#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
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
    int n, x;
    cin >> n >> x;

    vi nums;

    map<int, int> sobrou;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.pb(temp);
    }

    sort(all(nums));

    int buscado = 0;
    int ultimo = -1;
    for (int i = 0; i < n; i++)
    {
        if (ultimo == nums[i])
        {
            sobrou[ultimo]++;
            continue;
        }

        ultimo = nums[i];

        if (buscado == nums[i])
        {
            buscado++;
            continue;
        }

        if (buscado - x >= 0 && sobrou[buscado % x] > 0)
        {
            buscado++;
            continue;
        }
        else
        {
            cout << buscado << endl;
            return;
        }
    }

    cout << buscado + 1 << endl;
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
