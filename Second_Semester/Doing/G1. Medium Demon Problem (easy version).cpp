#include "Headers.h"
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

void solve()
{
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> anterior(n, 0);
    vector<int> atual(n, 1);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        r[i] = temp - 1;
    }

    int ano = 1;
    while (anterior != atual)
    {
        anterior = atual;
        vector<int> temp = atual;
        ano++;

        for (int i = 0; i < n; i++)
        {
            if (atual[i] >= 1)
            {
                temp[r[i]]++;
                temp[i]--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            atual[i] = temp[i] >= 1 ? 1 : 0;
        }
    }
    cout << ano << endl;
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
