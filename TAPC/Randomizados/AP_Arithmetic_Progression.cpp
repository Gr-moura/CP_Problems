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
bool greaterThan(int x)
{
    cout << "> " << x << endl;
    cout.flush();

    int val;
    cin >> val;

    return val;
}

int getValueInPosition(int pos)
{
    cout << "? " << pos << endl;
    cout.flush();

    int val;
    cin >> val;

    return val;
}

// Consigo achar o maior elemento com 30 queries, fazendo busca binária
// Se eu pego 30 valores aleatórios a partir disso, eu posso estimar a diferença comum

// Ordeno os 30 números e pego o mdc de todas as diferenças

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n;
    cin >> n;

    int left = 1, right = 1e9;

    // Achar o maior valor
    int it = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (greaterThan(mid)) left = mid + 1;
        else right = mid;

        it++;
    }

    int maxValue = left;
    vi values;
    for (int i = 0; i < 60 - it; i++)
    {
        int idx = rng32() % n + 1;
        values.push_back(getValueInPosition(idx));
    }

    sort(all(values));
    int diff = 0;
    for (int i = 1; i < (int)values.size(); i++)
    {
        diff = gcd(diff, values[i] - values[i - 1]);
    }

    int valorInicial = maxValue - diff * (n - 1);

    cout << "! " << valorInicial << " " << diff << endl;
    cout.flush();
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
