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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s[0] == '1')
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                cout << "NO\n";
                return;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    if (s[0] == '0')
    {
        if (s[1] == '1')
        {
            cout << "NO\n";
            return;
        }
    }

    if (s.contains("101"))
    {
        cout << "NO\n";
        return;
    }

    vi ans(n, 0);
    vi qt(n + 1, 0);
    vi posUns;
    posUns.pb(-1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            posUns.pb(i);
            ans[i] = i + 1;
            qt[i + 1]++;
        }
    }
    posUns.pb(n);

    for (int i = 0; i < n;)
    {
        while (i < n && s[i] == '1')
            i++;
        int l = i;
        dbg(l);

        while (i < n && s[i] == '0')
            i++;
        int r = i;
        dbg(r);

        int valorAtual = r;
        while (l < r)
        {
            if (r != l) ans[r--] = valorAtual++;
            ans[l++] = valorAtual++;
        }
    }

    cout << "YES" << endl;
    printv(ans);
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
