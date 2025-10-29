/*
ID: gabriel139
LANG: C++
TASK: dualpal
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
map<int, char> dict = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
                       {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};

bool isPalindromic(string &s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }

    return true;
}

string turnIntoBaseB(int num, int b)
{
    string s;
    while (num > 0)
    {
        int res = num % b;
        s += dict[res];
        num /= b;
    }

    reverse(all(s));
    return s;
}

void solve()
{
    int n, s;
    cin >> n >> s;

    for (int i = s + 1; n > 0; i++)
    {
        int qt = 0;
        for (int b = 2; b <= 10; b++)
        {
            string teste = turnIntoBaseB(i, b);

            if (isPalindromic(teste))
            {
                qt++;
            }

            if (qt == 2)
            {
                cout << i << endl;
                n--;

                break;
            }
        }
    }
}

int32_t main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

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
