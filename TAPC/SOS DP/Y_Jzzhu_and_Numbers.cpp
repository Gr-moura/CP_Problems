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
#define endl '\n'
#define cnt first
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

template <int p> struct mod_int
{
    // Exponenciacao rapida
    // (b^e mod p) em O(log(e))
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

    // Inverso modular de b mod p, onde p é primo
    ll inv(ll b) { return expo(b, p - 2); }

    using m = mod_int;
    ll v;

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

const int MOD = 1e9 + 7;
typedef mod_int<(int)MOD> mint;

const int MAX_BIT = 20;
const int SIZE = 1 << MAX_BIT;

// soma de super-conjunto
vector<ll> sos_dp(vector<ll> F)
{
    int N = __builtin_ctz(F.size());
    assert((1 << N) == F.size());

    for (int i = 0; i < N; i++)
        for (int mask = 0; mask < (1 << N); mask++)
            if (~mask >> i & 1) F[mask] += F[mask ^ (1 << i)];
    return F;
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> F(SIZE, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        F[temp]++;
    }

    vector<ll> cnt = sos_dp(F);
    vector<ll> pot(SIZE);

    pot[0] = 1;
    for (int i = 1; i < SIZE; i++)
        pot[i] = (pot[i - 1] * 2) % MOD;

    ll ans = 0;
    for (int mask = 0; mask < SIZE; mask++)
    {
        // Quantidade de subsequencias cujo AND contem 'mask' como subconjunto
        ll superConj = (pot[cnt[mask]] - 1 + MOD) % MOD;

        // Se numero de bits eh impar, subtrai. Se par, soma.
        if (__builtin_popcount(mask) % 2 == 1) ans = (ans - superConj + MOD) % MOD;
        else ans = (ans + superConj) % MOD;
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
