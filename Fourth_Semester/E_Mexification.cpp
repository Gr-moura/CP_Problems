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
int n, k;

int sum(vi &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];

    return sum;
}

int aplicarK(vi &v, int &k)
{
    if (k == 0) return sum(v);
    vi menorTirando(n, -1);
    vi qt(n + 1, 0);

    int m = -1;
    for (int i = 0; i < n; i++)
    {
        qt[v[i]]++;
        if (v[i] == m + 1) m++;
    }

    int jaPassou = 0;
    for (int i = 0; i <= n; i++)
    {
        if (qt[i] == 0)
        {
            while (jaPassou < n)
            {
                v[jaPassou] = i;
                jaPassou++;
            }
        }

        if (qt[i] == 1)
        {
            jaPassou++;
            continue;
        }

        if (qt[i] >= 2)
        {
            while (jaPassou < n && v[jaPassou] == i)
            {
                v[jaPassou] = m + 1;
                jaPassou++;
            }
        }

        if (jaPassou == n) break;
    }

    k--;
    return sum(v);
}
void transform()
{
    for (int i = 0; i <= n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    int mng = 0;
    for (; cnt[mng]; mng++)
    {
    } // mng = primeiro == 0
    for (int i = 0; i < n; i++)
    {
        int mn = mng;
        int v = a[i];
        if (cnt[v] == 1) mn = min(mng, v);
        a[i] = mn;
    }
}

void solve()
{
    cin >> n >> k;

    vi v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    sort(all(v));

    aplicarK(v, k);
    int sum1 = aplicarK(v, k);
    int sum2 = aplicarK(v, k);

    int ans = k % 2 == 1 ? sum1 : sum2;

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
