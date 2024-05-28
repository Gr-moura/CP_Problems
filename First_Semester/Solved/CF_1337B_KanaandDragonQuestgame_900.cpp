#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define int long long
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) ((int)((a).size()))
#define char unsigned char

typedef long double ld;

void solve()
{
    int health, voids, lightning;
    cin >> health >> voids >> lightning;

    while (health > 20 && voids > 0)
    {
        health = health / 2 + 10;
        voids--;
    }

    while (lightning > 0)
    {
        health -= 10;
        lightning--;
    }

    if (health <= 0)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

#ifdef ONPC
        cout << "__________________________" << endl;
#endif
    }

#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
