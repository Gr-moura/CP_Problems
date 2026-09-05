/*
ID: gabriel139
LANG: C++
TASK: sort3
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back

// Índice base 0 do primeiro elemento maior ou igual a x em log n
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())

// Índice base 0 do primeiro elemento  estritamente maior que x em log n
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    vi qt(4, 0);
    vi a(n);
    for (auto &i : a)
    {
        cin >> i;
        qt[i]++;
    }

    int trocados = 0;
    int errados[4][4];
    memset(errados, 0, sizeof errados);
    for (int i = 0; i < qt[1]; i++)
    {
        if (a[i] != 1)
        {
            errados[1][a[i]]++;
            trocados++;
        }
    }

    for (int i = qt[1]; i < qt[1] + qt[2]; i++)
    {
        if (a[i] != 2)
        {
            errados[2][a[i]]++;
            trocados++;
        }
    }

    for (int i = qt[1] + qt[2]; i < n; i++)
    {
        if (a[i] != 3)
        {
            errados[3][a[i]]++;
            trocados++;
        }
    }

    int ans = 0;

    ans += min(errados[1][3], errados[3][1]);
    ans += min(errados[2][3], errados[3][2]);
    ans += min(errados[1][2], errados[2][1]);

    trocados -= 2 * ans;
    ans += 2 * (trocados / 3);

    cout << ans << endl;
}

int32_t main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
