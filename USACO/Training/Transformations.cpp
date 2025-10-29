/*
ID: gabriel139
LANG: C++
TASK: transform
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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n;
bool igual(vector<string> &a, vector<string> &b)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]) return false;
    }

    return true;
}

vector<string> rotate90(vector<string> &a)
{
    // i = linha, y = coluna
    // (i, j) -> (j, n - 1 - i)
    vector<string> res(n, string(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - 1 - i] = a[i][j];
        }
    }

    return res;
}

vector<string> rotate180(vector<string> &a)
{
    vector<string> res = rotate90(a);
    res = rotate90(res);

    return res;
}

vector<string> rotate270(vector<string> &a)
{
    vector<string> res = rotate90(a);
    res = rotate90(res);
    res = rotate90(res);

    return res;
}

vector<string> reflect(vector<string> &a)
{
    vector<string> res(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(res[i][j], res[i][n - 1 - j]);
        }
    }

    return res;
}

void print(vector<string> &a)
{
    for (auto s : a)
        cout << s << endl;
}

void solve()
{
    cin >> n;

    vector<string> inicial(n);
    for (int i = 0; i < n; i++)
        cin >> inicial[i];

    vector<string> final(n);
    for (int i = 0; i < n; i++)
        cin >> final[i];

    vector<string> s = rotate90(inicial);
    if (igual(s, final))
    {
        cout << 1 << endl;
        return;
    }

    s = rotate180(inicial);
    if (igual(s, final))
    {
        cout << 2 << endl;
        return;
    }

    s = rotate270(inicial);
    if (igual(s, final))
    {
        cout << 3 << endl;
        return;
    }

    s = reflect(inicial);
    if (igual(s, final))
    {
        cout << 4 << endl;
        return;
    }

    s = reflect(inicial);
    s = rotate90(s);
    if (igual(s, final))
    {
        cout << 5 << endl;
        return;
    }

    s = reflect(inicial);
    s = rotate180(s);
    if (igual(s, final))
    {
        cout << 5 << endl;
        return;
    }

    s = reflect(inicial);
    s = rotate270(s);
    if (igual(s, final))
    {
        cout << 5 << endl;
        return;
    }

    if (igual(inicial, final))
    {
        cout << 6 << endl;
        return;
    }

    cout << 7 << endl;
}

int32_t main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

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
