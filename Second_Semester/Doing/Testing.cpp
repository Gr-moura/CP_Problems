#include <algorithm>
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
vector<int> memo;

int dp(int dia, char ultimo, int vezes)
{
    if (vezes >= 3)
        return -LINF;
    if (dia <= 0)
        return 0;

    if (memo[dia] != -1)
        return memo[dia];

    int A = 1, B = 1, C = 1;

    if (ultimo == 'a')
        A = vezes + 1;

    else if (ultimo == 'b')
        B = vezes + 1;

    else if (ultimo == 'c')
        C = vezes + 1;

    vector<int> ma(3);
    ma[0] = dp(dia - 1, 'a', A) + a[dia - 1];
    ma[1] = dp(dia - 1, 'b', B) + b[dia - 1];
    ma[2] = dp(dia - 1, 'c', C) + c[dia - 1];

    return memo[dia] = *max_element(all(ma));
}

void solve()
{
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    memo.resize(n + 10, -1);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 0; i < N; i++)
    {
    }

    cout << dp(n, 'b', 0);
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
