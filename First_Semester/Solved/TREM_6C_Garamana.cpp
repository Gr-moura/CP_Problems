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

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    vector<int> qt_A(26, 0);
    string A;
    cin >> A;

    for (auto c : A)
    {
        qt_A[c - 'a']++;
    }

    vector<int> qt_B(26, 0);
    string B;
    cin >> B;
    for (auto c : B)
    {
        if (c != '*')
            qt_B[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (qt_B[i] > qt_A[i])
        {
            cout << "N\n";
            return;
        }
    }

    cout << "S";
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
