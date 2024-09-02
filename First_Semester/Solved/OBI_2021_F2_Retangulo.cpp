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

const int MAX = 1e5 + 10;
vi prefixos(MAX, 0);

int somar(int l, int r, int n)
{
    int ans = 0;

    if (r > n && l <= n)
    {
        ans += prefixos[r - n];
        ans += prefixos[n] - prefixos[l];
    }

    else if (r <= n && l <= n)
    {
        ans += prefixos[r] - prefixos[l];
    }

    else
    {
        return -1;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vi arcos(n);

    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arcos[i];
        soma += arcos[i];
        prefixos[i + 1] = soma;
    }

    if (soma % 2 != 0)
    {
        cout << "N\n";
        return;
    }

    int l = 0;
    int r = 1;
    int contador = 0;
    int buscar = soma / 2;

    while (r < 2 * n)
    {
        // O que importa para descobrirmos se existe um retângulo é o numero
        // de diagonais diferentes no circulo. Se existem duas diagonais
        // diferentes ou mais, e possivel de se criar um retangulo ali (ja
        // que as diagonais de um retangulo sao sempre congruentes)
        //
        // Vemos as posicoes de L e R e o valor entre elas. Se for igual a buscar,
        // como so existe apenas uma diagonal por ponto, passamos ambos adiante,
        // pois se aumentasse so em um, ou ficaria muito baixo, ou muito alto
        //
        // Se for menor, aumentamos o R e mantemos o L, pois se diminuirmos o L,
        // estaremos olhando em uma diagonal ja verificada.
        //
        // Se for maior, aumentamos o L, uma vez que, se existisse uma diagonal
        // naquele ponto, ja teriamos passado por ela, ja que existe apenas uma

        int atual = somar(l, r, n);

        if (atual == -1)
            break;

        if (atual > buscar)
            l++;

        else if (atual < buscar)
            r++;

        else
        {
            contador++;
            l++;
            r++;
        }

        if (contador == 4)
        {
            cout << "S\n";
            return;
        }
    }

    cout << "N\n";
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    fast_io;
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
