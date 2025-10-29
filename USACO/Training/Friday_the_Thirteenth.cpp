/*
ID: gabriel139
LANG: C++
TASK: friday
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
bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;

    return false;
}

void solve()
{
    int n;
    cin >> n;

    vector<pii> meses{{1, 31}, {2, 28}, {3, 31}, {4, 30},  {5, 31},  {6, 30},
                      {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    vi qt(7, 0);
    int diaAtual = 1;
    for (int i = 0; i < n; i++)
    {
        int anoAtual = 1900 + i;
        for (auto [mes, dias] : meses)
        {
            if (mes == 2 and isLeapYear(anoAtual)) dias++;
            for (int j = 1; j <= dias; j++)
            {
                diaAtual++;
                diaAtual %= 7;

                if (j != 13) continue;

                qt[diaAtual]++;
            }
        }
    }

    for (int i = 0; i < 7; i++)
        cout << qt[i] << " \n"[i == 6];
}

int32_t main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

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
