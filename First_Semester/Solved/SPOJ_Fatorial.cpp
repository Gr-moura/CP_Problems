#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define forn(variavel, inicio, fim) for(long long variavel = inicio; variavel < fim; variavel++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define vi vector <int>
#define ll long long
#define endl '\n'


int main()
{
    int t; cin >> t;
    vi digitos(1000001);
    digitos[0] = 1;
    
    ll ultimodigito, resto = 1;
    

    for(int i = 1; i <= 1000000; i ++)
    {
        resto = resto * i;
        while (resto % 10 == 0) resto /= 10;
        resto = resto % 10000000;
        ultimodigito = resto % 10;

        digitos[i] = ultimodigito;

    }

    int count = 1;

    do
    {
        cout << "Instancia " << count << endl;
        cout << digitos [t] << endl;
        cout << endl;

        count++;

    } while (scanf("%d", &t) != EOF);
    
    return 0;
}