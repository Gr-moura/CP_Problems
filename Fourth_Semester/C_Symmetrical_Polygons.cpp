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

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    map<int, int> qt;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        qt[a[i]]++;
    }

    if (n == 3)
    {
        if ((a[0] + a[1] <= a[2]) or (a[0] + a[2] <= a[1]) or (a[1] + a[2] <= a[0]))
        {
            cout << 0 << endl;
            return;
        }
    }

    if (qt.size() == n)
    {
        cout << 0 << endl;
        return;
    }

    int sum2 = 0;
    vi possiveisDesiguais;
    int ladosPares = 0;

    for (auto p : qt)
    {
        if (p.s % 2 == 0)
        {
            sum2 += p.f * p.s;
            ladosPares += p.s;
        }

        else
        {
            sum2 += p.f * (p.s - 1);
            ladosPares += p.s - 1;

            possiveisDesiguais.push_back(p.f);
        }
    }

    sort(all(possiveisDesiguais), greater<>());
    if (possiveisDesiguais.size() == 0)
    {
        cout << sum2 << endl;
        return;
    }

    if (possiveisDesiguais.size() == 1)
    {
        if (possiveisDesiguais[0] < sum2)
        {
            sum2 += possiveisDesiguais[0];
        }

        cout << sum2 << endl;
        return;
    }

    int usados = 0;
    for (int i = 0; i < possiveisDesiguais.size() - 1; i++)
    {
        if (possiveisDesiguais[i] < sum2 + possiveisDesiguais[i + 1])
        {
            sum2 += possiveisDesiguais[i] + possiveisDesiguais[i + 1];
            usados = 2;
            break;
        }
    }

    if (!usados)
    {
        for (int l = 0; l < possiveisDesiguais.size(); l++)
        {
            if (possiveisDesiguais[l] < sum2)
            {
                sum2 += possiveisDesiguais[l];
                usados++;
                break;
            }
        }
    }

    if (ladosPares == 2 && usados == 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << sum2 << endl;
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
