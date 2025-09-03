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
int dist(char a, char b)
{
    return min(abs(a - b), 10 - abs(a - b));
}

void solve()
{
    string l, r;
    cin >> l >> r;

    if (l == r)
    {
        cout << l.length() * 2 << endl;
        return;
    }

    int n = l.length();
    int ans = 0;

    int ptr = 0;
    while (ptr < n and l[ptr] == r[ptr])
    {
        ptr++;
        ans += 2;
    }

    if (l[ptr] + 1 < r[ptr])
    {
        cout << ans << endl;
        return;
    }

    ans++;
    for (int i = ptr + 1; i < n; i++)
    {
        if (l[i] == '9' and r[i] == '0')
        {
            ans++;
            continue;
        }
        break;
    }

    cout << ans << endl;
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
