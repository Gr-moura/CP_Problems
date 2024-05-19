#include <bits/stdc++.h>
using namespace std;


int main(){
    int vezes, participantes, soma, num, menor,contar;
    scanf("%d ", &vezes);
    vector <int> v;
    vector <int> somas;

    for (int i = 0; i<vezes; i++){
        v.clear();
        scanf("%d ", &participantes);

        for (int k = 0; k<participantes; k++){
            scanf("%d ", &num);
            v.push_back(num);
        }

        sort(v.begin(),v.end());

        menor = v[v.size() - 1]*v[v.size() - 1];
        contar = 0;
        for (int j = 0; j < v.size() -1 - j; j++){
            soma = v[j] + v[v.size() - 1 - j];
            if (soma <= menor){
                menor = soma;
            }
        }
        for (int j = 0; j < v.size(); j++){
            for (int p = j + 1; p < v.size(); p++){

                soma = v[j] + v[p];
                if (soma == menor){
                    contar ++;
                }
            }
        }
        printf ("%d\n", contar);

    }


    return 0;
}
