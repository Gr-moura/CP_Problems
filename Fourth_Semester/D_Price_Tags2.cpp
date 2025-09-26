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

const int MOD = 1e9 + 7, MAX = 2e5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, y;
vi qtTags;
vi c;

int income(double x)
{
    vi copiaTags(qtTags);
    int ganho = 0;
    for (int i = 0; i < n; i++)
    {
        int val = ceil(c[i] / x);
        ganho += val;

        if (copiaTags[val] > 0)
        {
            copiaTags[val]--;
            continue;
        }

        ganho -= y;
    }

    return ganho;
}

void solve()
{
    cin >> n >> y;

    c.assign(n, 0);
    qtTags.assign(1000, 0);

    int valorMax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        valorMax = max(valorMax, c[i]);
        qtTags[c[i]]++;
    }

    int maxIncome = -LINF;

    for (int x = 2; x <= valorMax; x++)
    {
        maxIncome = max(maxIncome, income(x));
    }

    maxIncome = max(maxIncome, income(MAX));

    cout << maxIncome << endl;
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