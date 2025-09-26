/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 2e5 + 10, maxn = 2e6;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int n, y;
int freq[maxn];
int pfreq[maxn + 1];

int income(int x)
{
    // O maior valor sempre será valorMax / x,
    // então só precisamos olhar até ele

    // A quantidade de pessoas com um valor = p
    // é [x * (p - 1) + 1, x * p]

    int ganho = -LINF;
    for (int p = 1; p * x < maxn; p++)
    {
        if (ganho == -LINF) ganho = 0;
        int qtPessoas = pfreq[x * p] - pfreq[x * (p - 1)];
        ganho += qtPessoas * p;
        int tagsFaltando = max(0ll, qtPessoas - freq[p]);
        ganho -= y * tagsFaltando;
    }

    return ganho;
}

void solve()
{
    cin >> n >> y;

    vi c(n, 0);
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        freq[c[i]]++;
    }

    pfreq[0] = 0;
    for (int i = 1; i < maxn; i++)
    {
        pfreq[i] = pfreq[i - 1] + freq[i];
    }

    // Para todo x >= valorMax, o valor da tag sempre será 1
    // Se então calcularmos o income para todos os x <= valorMax
    // em O(valorMax / x), teremos uma resposta em
    // O(valorMax * log valorMax)

    int maxIncome = -LINF;
    for (int x = 2; x <= MAX; x++)
    {
        maxIncome = max(maxIncome, income(x));
    }

    maxIncome = max(maxIncome, n - y * (n - freq[1]));

    cout << maxIncome << endl;
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
