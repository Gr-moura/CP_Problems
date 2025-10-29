/*
ID: gabriel139
LANG: C++
TASK: beads
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

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n;
string s;
int testarEsq(int index, char inicialL)
{
    int atual = 0, l = index;

    while (l >= 0 and (s[l] == 'w' or s[l] == inicialL))
        atual++, l--;

    return atual;
}

int testarDir(int index, char inicialR)
{
    int atual = 0, r = index + 1;

    while (r < 2 * n and (s[r] == 'w' or s[r] == inicialR))
        atual++, r++;

    return atual;
}

void solve()
{
    cin >> n;
    cin >> s;

    s += s;

    int ans = 0;
    // lado esquerdo vira [0, i] e direito vira (i, 2 * n)
    for (int i = 0; i < 2 * n - 1; i++)
    {
        char inicialL = s[i], inicialR = s[i + 1];

        if (inicialL == 'w' and inicialR == 'w')
        {
            ans = max(testarEsq(i, 'b') + testarDir(i, 'b'), ans);
            ans = max(testarEsq(i, 'b') + testarDir(i, 'r'), ans);
            ans = max(testarEsq(i, 'r') + testarDir(i, 'b'), ans);
            ans = max(testarEsq(i, 'r') + testarDir(i, 'r'), ans);
            continue;
        }

        if (inicialL == 'w')
        {
            ans = max(testarEsq(i, 'b') + testarDir(i, inicialR), ans);
            ans = max(testarEsq(i, 'r') + testarDir(i, inicialR), ans);
            continue;
        }

        if (inicialR == 'w')
        {
            ans = max(testarEsq(i, inicialL) + testarDir(i, 'b'), ans);
            ans = max(testarEsq(i, inicialL) + testarDir(i, 'r'), ans);
            continue;
        }

        ans = max(testarEsq(i, inicialL) + testarDir(i, inicialR), ans);
    }

    ans = min(ans, n);

    cout << ans << endl;
}

int32_t main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
