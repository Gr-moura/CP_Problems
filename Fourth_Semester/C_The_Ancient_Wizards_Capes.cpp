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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 676767677, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (auto &i : a)
        cin >> i;

    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }

    vi preffixL(n + 1, 0);
    vi suffixR(n + 1, 0);
    vi L(n, -1);

    // a[i] = preffixL[i] + suffixR[i];
    // preffixL[i] = preffixL[i - 1] + Li == 1?
    // suffixR[i] = suffixR[i + 1] + Ri == 1?

    // suffixR[i] = suffixR[i + 1] + 1 - (preffixL[i] - preffixL[i - 1])

    // Ai-1 = 1 + Ai+1 - Li - Li-1

    int ans = 0;
    for (int r = 0; r < 2; r++)
    {
        L[0] = r, preffixL[0] = r;
        int pos = 1;
        for (int i = 1; i < n; i++)
        {
            L[i] = 1 + a[i] - a[i - 1] - L[i - 1];
            if (L[i] != 0 and L[i] != 1)
            {
                pos = 0;
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            preffixL[i] = preffixL[i - 1] + L[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suffixR[i] = suffixR[i + 1] + 1 - L[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] != suffixR[i] + preffixL[i])
            {
                pos = 0;
                break;
            }
        }

        ans += pos;
    }

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
