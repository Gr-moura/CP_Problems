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

const int MOD = 998244353, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

// Aritmetica Modular
//
// O mod tem q ser primo

template <int p> struct mod_int
{
    ll expo(ll b, ll e)
    {
        ll ret = 1;
        while (e)
        {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p - 2); }

    using m = mod_int;
    int v;
    mod_int() : v(0) {}
    mod_int(ll v_)
    {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m &operator+=(const m &a)
    {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m &operator-=(const m &a)
    {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m &operator*=(const m &a)
    {
        v = v * ll(a.v) % p;
        return *this;
    }
    m &operator/=(const m &a)
    {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator-() { return m(-v); }
    m &operator^=(ll e)
    {
        if (e < 0)
        {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        // possivel otimizacao:
        // cuidado com 0^0
        // v = expo(v, e%(p-1));
        return *this;
    }
    bool operator==(const m &a) { return v == a.v; }
    bool operator!=(const m &a) { return v != a.v; }

    friend istream &operator>>(istream &in, m &a)
    {
        ll val;
        in >> val;
        a = m(val);
        return in;
    }
    friend ostream &operator<<(ostream &out, m a) { return out << a.v; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
};

typedef mod_int<(int)998244353> mint;
int fact[10000], invfact[10000];

// Exponenciacao rapida
// (x^y mod m) em O(log(y))

ll fexp(ll x, ll y, ll m)
{
    ll ret = 1;
    while (y)
    {
        if (y & 1) ret = (ret * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

// Inverso modular de x mod m, onde m é primo
// O (log m)
ll inv(ll x, ll m)
{
    // Usando o pequeno teorema de Fermat

    // x^(m-1) ≡ 1 (mod m)
    // x*x^(m-2) ≡ 1 (mod m)

    // Portanto, o inverso modular de x é x^(m-2) mod m

    return fexp(x, m - 2, m);
}

mint escolheNPequeno(int n, int k)
{
    return mint(fact[n]) * mint(invfact[k]) * mint(invfact[n - k]);
}

mint escolheNGrande(int n, int k)
{
    mint numerador = 1;
    for (int i = 0; i < k; i++)
        numerador *= mint(n - i);

    return numerador * mint(invfact[k]);
}

void solve()
{
    fact[0] = 1, invfact[0] = 1;
    for (int i = 1; i < 10000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = inv(fact[i], MOD);
    }

    int n, m, k;
    cin >> n >> m >> k;

    if (m % k != 0)
    {
        cout << 0 << endl;
        return;
    }

    m /= k;

    mint ans = 0;
    for (int i = 0; i <= n - k + 1; i++)
    {
        int resto = m - (i * k);
        if (resto < 0) break;

        mint viola = escolheNPequeno(n - k + 1, i);

        int sep = 2 * n - k;
        mint restante = escolheNGrande(resto + sep, sep);

        mint termo = viola * restante;

        if (i % 2 == 1) ans -= termo;
        else ans += termo;
    }

    cout << ans << endl;
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
