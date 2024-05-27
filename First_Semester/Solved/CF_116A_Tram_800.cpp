#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int t; cin >> t; int qt = 0, maior = 0;
    
    while (t--) 
    {
        int sair, entrar; cin >> sair >> entrar;
        qt = qt - sair + entrar;
        if (qt > maior) maior = qt;
        
    }
    cout << maior;
    return 0;
}