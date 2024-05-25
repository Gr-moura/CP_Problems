#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base ::sync_with_stdio(0);                                                                                     \
    cin.tie(0);

#define int long long
#define vi vector<int>
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) ((int)((a).size()))
#define char unsigned char

typedef long double ld;
int formula(int i)
{
    int resposta;
    i = i - 1;
    resposta = (3 * (i * i) + 7 * i + 4) / 2;
    return resposta;
}

int32_t main()
{
    _ int t = 1;
    cin >> t;

    while (t--)
    {
        int buscar;
        cin >> buscar;
        int inicio = 1, fim = 9e8;

        while (!(formula((inicio + fim) / 2) <= buscar && formula((inicio + fim) / 2 + 1) >= buscar))
        {
            int buscamos = formula((inicio + fim) / 2);
            if (buscamos == buscar || formula((inicio + fim) / 2 + 1) == buscar)
            {
            }
            else if (buscamos > buscar)
                fim = (inicio + fim) / 2;
            else if (buscamos < buscar)
                inicio = (inicio + fim) / 2;
            if (buscamos == buscar || formula((inicio + fim) / 2 + 1) == buscar)
            {
                if (formula((inicio + fim) / 2 + 1) == buscar)
                    fim += 2;
                break;
            }

            // if (buscamos <= buscar && formula((inicio + fim) / 2 + 1) >= buscar)
        }
        cout << (inicio + fim) / 2 << endl;
    }

    return 0;
}
