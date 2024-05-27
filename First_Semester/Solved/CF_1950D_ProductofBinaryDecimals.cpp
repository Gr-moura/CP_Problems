#include <iostream>
using namespace std;

int main(){
    int vezes, a, fatorar,x;
    int vetor[17] = {10,11,101,11,111,1001,1011,1101,1111,10001,10011,10101,10111,11001,11011,11101,11111};
    cin >> vezes;
    while (vezes--){
        cin >> fatorar;
        x = 16;
        while (fatorar != 1) {

            if (fatorar%vetor[x]==0){
                fatorar = fatorar/vetor[x];
            } else if (x == 0){
                break;
            } else {
                x--;
            }
        }

        if (fatorar == 1){
            cout<<"YES\n";
        } else{
            cout<<"NO\n";
        }
    }

    return 0;
}
