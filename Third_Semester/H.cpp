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

vector<bool> Binario(int n)
{
    vector<bool> v;

    while (n > 0)
    {
        bool b = n % 2;
        v.push_back(b);
        n /= 2;
    }

    reverse(v.begin(), v.end());
    return v;
}

void solve()
{
    unsigned long long n;
    cin >> n;
    if (n % 2 == 0) n--;

    vector<bool> v = Binario(n);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
        }
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
