#include <bits/stdc++.h>
#include <cctype>
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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    string a;
    cin >> a;
    int maiusculas = 0, minusculas = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            maiusculas++;
        else
            minusculas++;
    }

    if (minusculas >= maiusculas)
    {
        for (auto &c : a)
            c = tolower(c);
    }

    else
        for (auto &c : a)
            c = toupper(c);

    cout << a;
}

int32_t main()
{
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
