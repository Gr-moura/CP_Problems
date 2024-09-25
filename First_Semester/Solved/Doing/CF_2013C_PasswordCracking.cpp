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

bool ask(string &s)
{
    cout << "? " << s << endl;
    ll v;
    cin >> v;
    return v;
}

void fin(string &s)
{
    cout << "! " << s << endl;
}

void solve()
{
    ll n;
    cin >> n;

    string s;
    while (s.size() < n)
    {
        s.push_back('0');
        if (ask(s))
        {
            continue;
        }

        s.back() = '1';
        if (ask(s))
        {
            continue;
        }

        s.pop_back();

        break;
    }

    while (s.size() < n)
    {
        string ns = '0' + s;
        s = move(ns);
        if (ask(s))
        {
            continue;
        }

        s.front() = '1';
    }

    fin(s);
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
