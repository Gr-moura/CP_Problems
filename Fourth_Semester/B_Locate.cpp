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

int encode(vi &a, int n)
{
    // Se 0, então 1 está à esquerda de n
    // Se 1, então 1 está à direita de n

    int x = 0;
    bool nPresente = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == n) nPresente = true;

        if (a[i] == 1 and nPresente == false) x = 0;
        else if (a[i] == 1 and nPresente == true) x = 1;
    }

    return x;
}

int ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int ret;
    cin >> ret;

    return ret;
}

void answer(int p)
{
    cout << "! " << p << endl;
    cout.flush();

    return;
}

// Se o n estiver na direita, quando a soma diminui, passamos do ponto
void decode(int n, int x)
{
    int l = 1, r = n;

    if (x == 0)
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (ask(1, mid) < n - 1) l = mid + 1;
            else r = mid;
        }

    else
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (ask(mid, n) < n - 1) r = mid - 1;
            else l = mid;
        }

    answer(l);
}

void solve()
{
    string player;
    cin >> player;

    // Se 0, então 1 está à esquerda de n
    // Se 1, então 1 está à direita de n

    if (player == "first")
    {
        int t;
        cin >> t;

        while (t--)
        {
            int n;
            cin >> n;

            vi a(n);
            for (auto &i : a)
                cin >> i;

            cout << encode(a, n) << endl;
            cout.flush();
        }

        return;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        decode(n, x);
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
