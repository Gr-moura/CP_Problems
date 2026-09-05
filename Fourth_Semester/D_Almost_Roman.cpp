/*
ID: gabriel139
LANG: C++
TASK: test
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
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int valorBase = 0;
    int qt = 0;

    vector<int> posProximoI;
    vector<int> posProximoXV;
    vector<int> posAnteriorI;
    set<int> posProximoInt;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == 'X')
        {
            if (i >= 1 && s[i - 1] == 'I') valorBase += 8;
            else valorBase += 10;
        }

        else if (c == 'V')
        {
            if (i >= 1 && s[i - 1] == 'I') valorBase += 3;
            else valorBase += 5;
        }

        else if (c == 'I') valorBase += 1;
        else qt++;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?') continue;
        if (i >= 1 && s[i - 1] == 'I') posAnteriorI.pb(i);
        if (i < n && (s[i + 1] == 'X' or s[i + 1] == 'V')) posProximoXV.pb(i);
        if (i < n && s[i + 1] == '?') posProximoInt.insert(i);
    }

    for (int ind = 0; ind < q; ind++)
    {
        int ans = valorBase;
        int qtRestante = qt;

        int x, v, i;
        cin >> x >> v >> i;

        if (qtRestante <= i)
        {
            ans += qtRestante;
            cout << ans << endl;

            continue;
        }
        vector<bool> usado(n, false);

        // Não vamos conseguir colocar I em todas as posições possíveis
        // Então vamos botar V ou X nas posições que antes tinham I

        for (auto pos : posAnteriorI)
        {
            if (qtRestante <= i or (v == 0 and x == 0)) break;

            if (v > 0 and qtRestante > 0)
            {
                ans += 3;
                qtRestante--, v--;
            }

            else if (x > 0 and qtRestante > 0)
            {
                ans += 8;
                qtRestante--, x--;
            }
            usado[pos] = true;
        }

        if (qtRestante <= i)
        {
            ans += qtRestante;
            cout << ans << endl;

            continue;
        }

        // Se não, vamos tentar intercalar I com V, até só sobrar 1
        for (auto pos : posProximoXV)
        {
            if (usado[pos]) continue;
            if (i == 0 or qtRestante == 0) break;
            if (i > 0 and qtRestante > 0)
            {
                ans--;
                i--, qtRestante--;
            }

            usado[pos] = true;
        }

        if (qtRestante <= i)
        {
            ans += qtRestante;
            cout << ans << endl;

            continue;
        }

        int posAnterior = -2;
        for (auto pos : posProximoInt)
        {
            if (qtRestante <= i or i == 0 or qtRestante == 0) break;
            if (usado[pos] or (pos < n - 1 and usado[pos + 1])) continue;

            if (pos == posAnterior + 1)
            {
                continue;
            }

            if (v > 0 and qtRestante > 1)
            {
                ans += 4;
                i--, qtRestante -= 2, v--;
            }

            else if (x > 0 and qtRestante > 1)
            {
                ans += 9;
                i--, qtRestante -= 2, x--;
            }

            usado[pos] = true;
            usado[pos + 1] = true;
        }

        if (qtRestante > i)
        {
            ans += i;
            qtRestante -= i;
        }

        else
        {
            ans += qtRestante;
            qtRestante = 0;
        }

        if (qtRestante > v)
        {
            ans += v * 5;
            qtRestante -= v;
        }

        else
        {
            ans += qtRestante * 5;
            qtRestante = 0;
        }

        if (qtRestante > x)
        {
            ans += x * 10;
            qtRestante -= x;
        }

        else
        {
            ans += qtRestante * 10;
            qtRestante = 0;
        }

        cout << ans << endl;
    }
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
