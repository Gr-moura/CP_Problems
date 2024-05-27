#include <bits/stdc++.h>
using namespace std;

#define forn(variavel, inicio, fim) for(long long variavel = inicio; variavel < fim; variavel++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define vi vector <int>
#define ll long long
#define endl '\n'

/*
    É obrigatório que sempre exista pelo menos um palito em cada um dos 
    lados do +, então escrevemos a equação da esquerda como 1 + x, 
    com x >= 1. Consequentemente, o outro lado também precisa ser
    igual a 1 + x. Logo, precisamos de 2x + 2 palitos para resolver 
    o problema.

    Assim, basta que a quantidade de palitos seja
    par e maior do que 2, para que a resposta esteja correta.
*/

void solve()
{
    int matches; cin >> matches;
    if (matches == 2) {cout << "2"; return;}
    if (matches % 2 == 0) {cout << "0"; return;}
    if (matches % 2 == 1) {cout << "1"; return;}

}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }
    
    return 0;
}