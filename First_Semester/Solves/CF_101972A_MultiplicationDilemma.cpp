#include <bits/stdc++.h>
using namespace std;

#define forn(variavel, inicio, fim) for(long long variavel = inicio; variavel < fim; variavel++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define vi vector <int>
#define ll long long
#define endl '\n'

int power (int num, int expoente)
{
    int res = 1;
    for (int i = 0; i < expoente; i++) res *= num;
    return res;
}

void solve()
{
    int a, b, count = 0, trocarsinal = 0; cin >> a >> b;

    if (a < 0 && b < 0) {a = -a; b = - b;}
    else if (a < 0) {a = -a; trocarsinal = 1;}
    else if (b < 0) {b = -b; trocarsinal = 1;}

    vector <int> digitos_a;
    vector <int> digitos_b;

    string sA = to_string(a);
    string sB = to_string(b);

    forn (i, 0, sA.size()) digitos_a.push_back(sA[i] - 48);
    forn (i, 0, sB.size()) digitos_b.push_back(sB[i] - 48);

    for (int i = digitos_a.size() - 1, index_a = 0; i >= 0; i--, index_a++)
    {
        if (digitos_a[index_a] == 0) continue;

        for (int j = digitos_b.size() - 1, index_b = 0; j >= 0; j--, index_b++)
        {
            if (digitos_b[index_b] == 0) continue;
            if (count > 0 && trocarsinal == 1) cout << " - ";
            else if (count > 0 && trocarsinal == 0) cout << " + ";

            if (count == 0 && trocarsinal == 1) cout << '-';

            cout << digitos_a[index_a]*power(10, i) << " x " << digitos_b[index_b]*power(10, j);
            count ++;
        }
    }


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
