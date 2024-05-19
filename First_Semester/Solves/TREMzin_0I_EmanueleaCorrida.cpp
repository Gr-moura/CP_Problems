    #include <bits/stdc++.h>
    using namespace std;
     
    int diferentes(vector <int> saida, vector <int> chegada, int tam){
        int  a = 0;
        for (int i = 0; i < tam;i++){
            if (saida[i] != chegada[i]) a = 1;
        }
        return a;
    }
    int encontrar_index (vector <int> saida, vector <int> chegada, int tam, int achar){
        for (int i = 0; i<tam; i++){
            if (saida[i] == achar) return i;
        }
        return 0;
    }
     
    int main(){
        int x, add, achar, ppp, index, temp, contar = 0;
        cin >> x;
        ppp = x - 1;
        vector <int> saida ;
        vector <int> chegada ;
     
        for (int i = 0; i<x;i++){
            cin>>add;
            saida.push_back(add);
        }
        for (int i = 0; i<x;i++){
            cin>>add;
            chegada.push_back(add);
        }
     
        while(diferentes(saida,chegada, ppp+1)){
     
            achar = chegada[ppp];
            if (achar == saida [ppp]) ppp -=1;
            else {
                index = encontrar_index(saida, chegada, x, achar);
     
                while (index < ppp){
                    temp = saida[index];
                    saida [index] = saida [index+1];
                    saida [index + 1] = temp;
                    contar++;
                    index++;
     
                }
     
                // encontrar index do achar na chegada e trocar os numeros ate ele estar na posicao correta
            }
        }
        cout<<contar;
     
     
     
        //for (int i = 0; saida)
     
     
     
    	return 0;
    }
