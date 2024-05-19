#include <bits/stdc++.h>
using namespace std;

#define forn(variavel, inicio, fim) for(int variavel = inicio; variavel < fim; variavel++)
#define endl '\n'


void solve()
{
    int altura, largura, x, y;
    cin >> altura >> largura >> x >> y;
    x++;
    y++;

    int vet [3];

    int maior = (x - 1)*largura;
    vet [0] = (largura - y)*altura;
    vet [1] = (altura - x)*largura;
    vet [2] = (y - 1)*altura;
    

    forn (i,0,3)
    {
        if (vet [i] > maior) maior = vet[i];
    }
    
    cout << maior << endl;
}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    
    return 0;
}