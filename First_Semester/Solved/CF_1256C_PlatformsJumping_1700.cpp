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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ehpossivel(vector<ii> posicoes_plataformas, int max_pulo, int limite)
{

    for (int i = 1; i < posicoes_plataformas.size(); i++)
    {
        if (posicoes_plataformas[i].f - (posicoes_plataformas[i - 1].s - 1) > max_pulo)
            return false;
    }

    if (posicoes_plataformas[(int)posicoes_plataformas.size() - 1].s - 1 + max_pulo < limite)
        return false;

    return true;
}

void solve()
{
    int width, platforms, max_pulo;
    cin >> width >> platforms >> max_pulo;
    vector<int> lengths(platforms);

    int caminhada = 0;

    for (int i = 0; i < platforms; i++)
    {
        cin >> lengths[i];
        caminhada += lengths[i] - 1;
    }

    int alcance = caminhada + max_pulo * (platforms + 1);

    if (alcance < width + 1)
    {
        cout << "NO\n" << endl;
        return;
    }

    cout << "YES\n";

    // 1 22 3 --> Leva ate o mais proximo do final --> 1 22      3
    // Se o pulo esta muito longe, a gente leva ate a anterior

    vector<ii> posicoes_plataformas(platforms);
    int pos = 0;

    for (int numero = 1; numero <= platforms; numero++)
    {
        posicoes_plataformas[numero - 1].f = pos;
        while (lengths[numero - 1]--)
        {
            pos++;
        }
        posicoes_plataformas[numero - 1].s = pos;
        // Nao conta onde acaba
    }

    int ultimo = (int)posicoes_plataformas.size() - 1;
    int aumentar;
    int fim, inicio;
    while (ehpossivel(posicoes_plataformas, max_pulo, width) == false)
    {
        vector<int> resposta(width, 0);

        // Pegamos a ultima, colocamos na maior distancia possivel do final
        // Se ainda for impossivel, fazemos isso com a anterior
        if (ultimo == (int)posicoes_plataformas.size() - 1)
            aumentar = (width - max_pulo) - (posicoes_plataformas[ultimo].s - 1);

        else
        {
            fim = posicoes_plataformas[ultimo + 1].f;
            inicio = posicoes_plataformas[ultimo].s - 1;

            aumentar = fim - max_pulo - inicio;
        }

        posicoes_plataformas[ultimo].f += aumentar;
        posicoes_plataformas[ultimo].s += aumentar;
        ultimo--;
    }

    vector<int> resposta(width, 0);
    for (int i = 1; i <= posicoes_plataformas.size(); i++)
    {
        for (int j = posicoes_plataformas[i - 1].f; j < posicoes_plataformas[i - 1].s; j++)
        {
            resposta[j] = i;
        }
    }

    for (int i = 0; i < width; i++)
    {
        cout << resposta[i] << " ";
    }
}

int32_t main()
{
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
