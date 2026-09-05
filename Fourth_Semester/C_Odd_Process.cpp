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

    vi a(n);
    for (auto &i : a)
        cin >> i;

    vi par, impar;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) par.pb(a[i]);
        else impar.pb(a[i]);
    }

    sort(all(par), greater<>());
    sort(all(impar), greater<>());

    if (impar.empty())
    {
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }

        cout << endl;
        return;
    }

    vi sumPar(n + 1, 0);
    int paresRetirados = 0;
    int maxPares = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - 1 < par.size()) sumPar[i] = sumPar[i - 1] + par[i - 1];
        else sumPar[i] = sumPar[i - 1];

        maxPares = max(maxPares, sumPar[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (i - 1 <= par.size())
        {
            cout << impar[0] + sumPar[i - 1] << " ";
            continue;
        }

        if (i == n)
        {
            if (i % 2 == par.size() % 2) cout << 0 << " ";
            else cout << impar[0] + maxPares << " ";

            continue;
        }

        if (par.empty())
        {
            if (i % 2 == 0) cout << 0 << " ";
            else cout << impar[0] << " ";

            continue;
        }

        if (i % 2 == par.size() % 2)
        {
            if (par.empty())
            {
                cout << 0 << " ";
                continue;
            }

            // Coloco todos os pares e tiro o máximo que posso de ímpar
            cout << impar[0] + sumPar[par.size() - 1] << " ";
            continue;
        }

        cout << impar[0] + maxPares << " ";
    }

    cout << endl;
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
