#include <bits/stdc++.h>
using namespace std;

int soma_digitos(int num){
    string s = to_string(num);
    int a = 0;
    for (auto k: s){
        a = a + (int)k - 48;
    }
    return a;


}

int main(){
    int vezes, r;
    int MAX = 200000;
    int v[MAX];
    v[0] = 0;
    cin >> vezes;

    for (int i = 1; i<=MAX; i++){
        v[i] = v[i-1] + soma_digitos(i);
    }

    while (vezes--){
        cin>>r;
        cout<<v[r];
    }


    return 0;
}

