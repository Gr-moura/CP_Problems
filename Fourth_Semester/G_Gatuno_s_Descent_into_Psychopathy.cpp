/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

long double power(long double x, int y)
{
    long double ret = 1;

    while (y)
    {
        if (y & 1) ret = (ret * x);
        y >>= 1;
        x = (x * x);
    }

    return ret;
}
void solve()
{
    double h1, h2, b;
    cin >> h1 >> h2 >> b;

    long double atual = (b - 1) / b;
    int tentativas = 1;

    while (h1 * atual > h2)
    {
        atual *= atual;
        tentativas *= 2;

        if (h1 * atual == h2)
        {
            cout << tentativas << endl;
        }
    }

    int l = tentativas / 2 + 1, r = tentativas;
    double mul = (b - 1) / b;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (h1 * (power(mul, mid)) <= h2) r = mid;

        else l = mid + 1;
    }

    cout << l << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
