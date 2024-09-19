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

bool compare(pii a, pii b)
{
    if (a.s < b.s)
    {
        return 1;
    }

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    vector<pii> ordX(n);
    vector<pii> ordY(n);

    unordered_map<int, int> X;
    unordered_map<int, int> Y;

    for (int i = 0; i < n; i++)
    {
        cin >> ordX[i].f >> ordX[i].s;

        X[ordX[i].f]++;
        Y[ordX[i].s]++;
    }

    sort(all(ordX));

    int ans = 0;

    // Existem 3 casos:
    // Mesmo x em 1 e mesmo y em outro
    // y1 = y2 e x do meio = X1 + X2 / 2 = y do meio = y + x do meio

    for (int i = 1; i < n; i++)
    {
        if (ordX[i - 1].f == ordX[i].f)
        {
            // Qts tem altura do primeiro
            ans += Y[ordX[i - 1].s] - 1;

            // Qts tem altura do segundo
            ans += Y[ordX[i].s] - 1;
        }
    }

    ordX = ordY;

    sort(all(ordY));

    for (int i = 1; i < n; i++)
    {
        if (ordY[i - 1].s == ordY[i].s)
        {
            int buscarX = (ordY[i - 1].s + ordY[i - 1].s + 1) / 2;

            if (buscarX == (ordY[i - 1].s + ordY[i - 1].s) / 2)
            {
                ans += X[buscarX];
            }
            // X do meio = X1 + X2 / 2
        }
    }

    cout << ans << endl;
    /*
        ordX = ordY;

        sort(all(ordY));

        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            if (ordX[i - 1].f == ordX[i].f)
            {
                // Mesmo y que o primeiro
                int lo = 0, hi = n - 1;
                int mid;
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;

                    if (ordY[mid].s >= ordX[i - 1].s)
                        hi = mid;

                    else
                        lo = mid + 1;
                }

                for (int j = mid; j < n; j++)
                {
                    if (ordY[j].s >)
                        if (ordY[j] != ordX[i - 1] && ordY[j] != ordX[i])
                }
            }
        }
        cout << endl;
    */
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
