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

using ull = unsigned long long;

const ull MAX_ELEMENT = 1e6 + 10, LOG_ME = 30; // Máxima quantidade de bits

ull basis[LOG_ME];
ull szBasis = 0;

void insertVector(ull mask) // O (LOG_ME)
{
    for (int i = LOG_ME - 1; i >= 0; i--)
    {
        if ((mask & 1ULL << i) == 0) continue; // O bit atual está desligado, fazemos nada

        if (!basis[i]) // Não temos ninguém controlando o bit atual
        {
            basis[i] = mask, szBasis++; // adicionamos como base
            return;
        }

        mask ^= basis[i]; // Subtraímos a base que já temos (XOR em Zd2 = adição = subtração)
    }
}

ull max_XORsum() // O (LOG_ME)
{
    ull retorno = 0;
    for (int i = LOG_ME - 1; i >= 0; i--)
    {
        if (retorno & 1ULL << i) continue; // Se o bit atual já está ligado, fazemos nada
        if (!basis[i]) continue;           // Se não temos como modificar o bit atual, fazemos nada

        retorno ^= basis[i]; // Ativamos o bit atual
    }

    return retorno;
}

ull findKthLargest_XORsum(ull kth)
{
    ull retorno = 0;
    ull l = 1, r = 1 << szBasis;
    for (int i = LOG_ME - 1; i >= 0; i--)
    {
        if (!basis[i]) continue; // Não podemos fazer nada

        ull mid = l + (r - l) / 2;
        if (kth <= mid) // Temos de desativar esse bit
        {
            r = mid;

            if ((retorno & 1ULL << i) == 0) continue;
            else retorno ^= basis[i];
        }

        else // Temos de ativar esse bit
        {
            l = mid + 1;

            if (retorno & 1ULL << i) continue;
            else retorno ^= basis[i];
        }
    }

    return retorno;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int s;
            cin >> s;
            insertVector(s);
        }

        else
        {
            int k;
            cin >> k;

            cout << findKthLargest_XORsum(k) << endl;
        }
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
