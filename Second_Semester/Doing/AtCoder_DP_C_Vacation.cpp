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

int n;
vector<int> a, b, c;
int memo[100010][4][4];

int dp(int dia, int ultimo, int vezes)
{
    if (vezes >= 3)
        return -LINF;

    if (dia == n)
        return 0;

    if (memo[dia][ultimo][vezes] != -1)
        return memo[dia][ultimo][vezes];

    int A = 1, B = 1, C = 1;

    if (ultimo == 0)
        A = vezes + 1;

    else if (ultimo == 1)
        B = vezes + 1;

    else if (ultimo == 2)
        C = vezes + 1;

    vector<int> ma(3, -LINF);

    if (A < 2)
        ma[0] = dp(dia + 1, 0, A) + a[dia];

    if (B < 2)
        ma[1] = dp(dia + 1, 1, B) + b[dia];

    if (C < 2)
        ma[2] = dp(dia + 1, 2, C) + c[dia];

    return memo[dia][ultimo][vezes] = *max_element(all(ma));
}

void solve()
{
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    cout << dp(0, 0, 0);
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
