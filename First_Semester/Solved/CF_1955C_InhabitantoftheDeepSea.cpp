#include <bits/stdc++.h>
using namespace std;


int main(){
    long long vezes, ships, sunk, primeira_metade, segunda_metade, add;
    long long attacks;
    cin >> vezes;
    while (vezes--){
        sunk = 0;
        cin >> ships;
        cin >> attacks;
        vector <int> vidas;

        for (int i = 0; i < ships; i++){
            cin >> add;
            vidas.push_back(add);
        }

        primeira_metade = (attacks + 1)/2;
        segunda_metade = attacks - primeira_metade;

        int inicio = 0, fim = ships - 1;

        while (primeira_metade >= vidas[inicio] && inicio <= fim){
            primeira_metade = primeira_metade - vidas[inicio];
            vidas [inicio] = 0;
            sunk = sunk + 1;
            inicio = inicio + 1;
        }

        if (inicio <= fim) {
            vidas [inicio] = vidas [inicio] - primeira_metade;
            while (segunda_metade >= vidas[fim] && vidas [fim] > 0){
                segunda_metade = segunda_metade - vidas[fim];
                sunk = sunk + 1;
                fim = fim - 1;
            }
        }

        cout << sunk << "\n" ;
    }

    return 0;
}

