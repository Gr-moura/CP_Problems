#include <bits/stdc++.h>
using namespace std;

int main(){
    int vezes,tamanho;
    cin >> vezes;
    vector <int> v;
    char matriz [15][15];
    while (vezes--){
        cin >> tamanho;
        for (int i = 0; i< tamanho; i++){
            cin >> matriz[i];
            for (int j =0; j< tamanho; j++){
                if (matriz[i][j]=='1'){
                    v.push_back(i+1);
                    v.push_back(j+1);
                }
        //Guardou as posicoes dos 1s
            }
        }
        //se for quadrado, a linha do primeiro é igual a linha do segundo
        //e a linha do ultimo é igual a linha do penultimo
        if (v[0] == v[2] && v[v.size() -2] == v[v.size()-4]){
            cout << "SQUARE\n";
        }else {
            cout << "TRIANGLE\n";
        }
        v.clear();

    }


    return 0;
}
