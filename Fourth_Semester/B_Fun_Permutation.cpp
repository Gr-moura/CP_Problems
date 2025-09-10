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
void solve()
{
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vi r(n);
    vi ans(n, 0);
    for (int i = 1; i <= n; i++)
    {
        r[i - 1] = i;
    }

    int index = 3;
    while (n % index != 0 and n % index != index - 1)
        index++;

    vi ind(index);
    ind[0] = index - 1;
    for (int i = 1; i < index; i++)
    {
        ind[i] = i - 1;
    }

    for (int i = 0; i < n; i++)
    {
        int complemento = (index - (v[i] % index)) % index;
        ans[i] = r[ind[complemento]];
        ind[complemento] += index;
    }

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
