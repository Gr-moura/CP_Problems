#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0)->sync_with_stdio(0);
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

void solve()
{
    string S;
    cin >> S;

    int n = S.size();
    S = " " + S;

    vector<int> Prefixo_Somas(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        Prefixo_Somas[i] = Prefixo_Somas[i - 1] + (S[i] == '0' ? -1 : 1);
    }

    map<int, int> cnt;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        /*
         * Para encontrarmos uma resposta, multiplicamos a pos do atual
         * com a pos de um elemento anterior com a mesma soma e, portanto,
         * precisamos que a mesma soma apareça no minímo duas vezes.
         *
         * Assim, a cnt[Prefixo_Somas[i]] começa em 0 e adicionamos a
         * posicao do ultimo elemento com aquele valor, pois na primeira vez
         * sera multiplicada por 0, e na segunda vez que aparecer, ira
         * ser multiplicada pela posicao do inicial.
         *
         * Ja quando sao 3 casos, nós multiplicaríamos a pos atual com
         * a soma do primeiro com aquele valor com o segundo com aquele valor,
         * pois a resposta seria
         *
         * = atual com 3 e atual com 2
         * = (n - atual + 1)(pos_primeiro) + (n - atual + 1)(pos_segundo)
         * = (n - atual + 1)(pos_primeiro + pos_segundo)
         *
         * E o caso do primeiro com o segundo ja teria sido encontrado anteriormente
         */

        ans += (n - i + 1) * cnt[Prefixo_Somas[i]];
        cnt[Prefixo_Somas[i]] += i + 1;

        cnt[Prefixo_Somas[i]] %= MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
