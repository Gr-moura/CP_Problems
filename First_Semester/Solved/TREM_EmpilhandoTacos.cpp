#include <bits/stdc++.h>
using namespace std;

int main(){
    long long pilhas, soma = 0, num,contar, maior, mirar;
    long long disponiveis;
    scanf("%lld ", &pilhas);
    scanf("%lld ", &disponiveis);
    vector <long long> v;
    vector <long long> div;

    for (int k = 0; k < pilhas; k++){
            scanf("%lld ", &num);
            soma = soma + num;
            v.push_back(num);
    }

    sort(v.begin(),v.end());
    maior = v[v.size() - 1];

    for (int h = v[0]; h<(maior+1)/2 ; h++){
        if (maior % h == 0){
            div.push_back(h);
        }
    }
    div.push_back(maior);
    //10,15,30

    // se nao for suficiente para igualar tudo
    if (disponiveis < maior*(pilhas - 1) - (soma - maior)){

       //ver as possibilidades de proximos divisores








    }   else{
        mirar = (disponiveis + soma)/pilhas;
    }

    printf("%lld", mirar);




    return 0;
}

