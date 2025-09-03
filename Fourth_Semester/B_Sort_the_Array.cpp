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
void solve()
{
    int n;
    cin >> n;

    vi v(n);
    vi o(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
        o[i] = a;
    }

    sort(all(o));

    int l = 0, r = n - 1;
    while (l < n && v[l] == o[l])
        l++;

    while (r >= 0 && v[r] == o[r])
        r--;

    if (l == n)
    {
        cout << "yes\n1 1\n";
        return;
    }

    reverse(v.begin() + l, v.begin() + r + 1);
    if (v == o)
    {
        cout << "yes\n" << l + 1 << " " << r + 1;
        return;
    }

    cout << "no\n";
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
