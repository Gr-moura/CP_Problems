#include <bits/stdc++.h>
using namespace std;

#define forn(variavel, inicio, fim) for(int variavel = inicio; variavel < fim; variavel++)
#define _ ios_base :: sync_with_stdio(0); cin.tie(0);
#define vll vector <long long>
#define ll long long
#define endl '\n'



void solve()
{
    int array_length, maior, temp, indexmaior; 
    
    cin >> array_length;
    vll vetor (array_length);
    vll swaps;

    forn (i, 0, array_length)
    {
        cin >> vetor[i];
    }

    int fim = array_length - 1, count = 0;

    while (fim > 0)
    {
        maior = vetor [0];
        indexmaior = 0;

        for (int i = 0; i <= fim; i ++)
        {
            if (vetor[i] > maior)
            { 
                maior = vetor [i];
                indexmaior = i;
            }
        }

        if (vetor [fim] != maior)
        {
            temp = vetor [fim];
            vetor[fim] = maior;
            vetor[indexmaior] = temp;


            swaps. push_back(fim);
            swaps. push_back(indexmaior);

            count ++;
        }
        fim --;

    }

    cout << count << endl;

    for (int i = 0; i < count * 2; i += 2)
    {
        cout << swaps [i] << " " << swaps [i + 1] << endl;
    }

}

int main()
{
    solve();
    
    return 0;
}