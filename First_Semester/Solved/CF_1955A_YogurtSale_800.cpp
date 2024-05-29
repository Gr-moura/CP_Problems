#include <bits/stdc++.h>
using namespace std;

int main(){
    int vezes, one, n, two, preco; cin >> vezes;
    while (vezes--){
        preco = 0;
        cin >> n;
        cin >> one;
        cin >> two;

        if (one*2>two){
            preco = (n/2) * two;
            n = n % 2;
            preco = preco + n * one;

        } else preco = n*one;
        cout << preco;



    }

    return 0;
}

