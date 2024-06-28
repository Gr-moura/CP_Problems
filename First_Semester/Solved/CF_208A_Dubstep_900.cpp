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
    string str;
    cin >> str;
    int ultimo = 0;
    bool primeiro = false;

    for (int i = 0; i < sz(str) - 1; i++)
    {
        if (i + 2 < sz(str) - 1)
        {
            string sequencia;
            sequencia += str[i];
            sequencia += str[i + 1];
            sequencia += str[i + 2];

            if (sequencia == "WUB")
            {
                if (i == 0)
                    primeiro = true;

                i += 2;
                ultimo = 1;
            }
            else
            {
                if (ultimo)
                {
                    ultimo = 0;
                    if (!primeiro)
                        cout << " ";
                    primeiro = false;
                }
                cout << str[i];
            }
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
