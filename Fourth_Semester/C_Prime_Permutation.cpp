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

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    // O grupo geral é composto por todas as posições, exceto por 1 e pelos primos maiores que |s| / 2
    int grupoGeral = n - 1;
    for (int i = (n / 2) + 1; i <= n; i++)
    {
        if (prime(i)) grupoGeral--;
    }

    int letraMaisComum = -1;
    int qtLetraMaisComum = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > qtLetraMaisComum)
        {
            qtLetraMaisComum = freq[i];
            letraMaisComum = i;
        }
    }

    if (qtLetraMaisComum < grupoGeral)
    {
        cout << "NO\n";
        return;
    }

    string ans(n, ' ');

    // Preencher o grupo geral com a letra mais comum, pulando a posição 1
    int qtUsada = 0;
    for (int i = 2; i <= n; i++)
    {
        // Se não for primo > n/2, então pertence ao grupo geral
        if (!(i > n / 2 && prime(i)))
        {
            ans[i - 1] = char('a' + letraMaisComum);
            qtUsada++;
        }
    }
    freq[letraMaisComum] -= qtUsada;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] != ' ') continue;

        for (int c = 0; c < 26; c++)
        {
            if (freq[c] > 0)
            {
                ans[i] = char('a' + c);
                freq[c]--;
                break;
            }
        }
    }

    cout << "YES\n" << ans << endl;
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

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
