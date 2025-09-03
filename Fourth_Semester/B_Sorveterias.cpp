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
int n, s;
vi coords;

bool pos(int minDist)
{
    int indexAtual = 1;
    int sorveteriasPostas = 1;
    while (indexAtual < n && sorveteriasPostas < s)
    {
        int distAtual = 0;
        while (indexAtual < n && distAtual < minDist)
        {
            distAtual += coords[indexAtual] - coords[indexAtual - 1];
            indexAtual++;
        }

        if (distAtual >= minDist) sorveteriasPostas++;
    }

    if (sorveteriasPostas == s) return true;

    return false;
}

void solve()
{
    cin >> n >> s;

    coords.resize(n);
    for (int i = 0; i < n; i++)
        cin >> coords[i];

    int l = 0, r = 1e9 + 10;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (!pos(mid))
        {
            r = mid - 1;
            continue;
        }

        l = mid + 1;
    }

    cout << l - 1 << endl;
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
