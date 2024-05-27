#include <bits/stdc++.h>
using namespace std;

// a i+1, j = aij + c
// a i, j+1 = aij + d

// a i+1, j -c = ai,j+1 - d

int main(){
    int vezes,add, n, c, d, no, stop; cin >> vezes;
    while (vezes--){
        no = 1;
        stop = 0;
        int contar = 0;
        cin >> n;
        cin >> c;
        cin >> d;

        int nova_matriz [n][n];
        vector <int> nova_lista;
        vector <int> lista;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> add;
                lista.push_back(add);
            }
        }
        sort(lista.begin(), lista.end());

        //transforma cada elemento da lista em a00
        for (int e = 0; e < n*n && stop == 0; e++){
            nova_matriz[0][0] = lista[e];

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (j + 1 < n){
                        nova_matriz [i][j+1] = nova_matriz [i][j] + d;
                    }
                    if (j + 1 < n){
                        nova_matriz [i+1][j] = nova_matriz [i][j] + c;
                    }
                }
            }

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    nova_lista.push_back(nova_matriz[i][j]);
                }
            }

            sort(nova_lista.begin(), nova_lista.end());

            for (int i = 0; i < n*n; i++){
                if (nova_lista[i] != lista[i]){
                    stop = 1;
                    break;
                } else contar ++;

            }

            if (contar == n*n){
                cout << "Yes\n";
                no = 0;
                stop = 1;
            }

        }
        if (no == 1) cout << "NO\n";


    }

    return 0;
}
