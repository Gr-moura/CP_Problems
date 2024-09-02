#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Número total de figurinhas
    int N = 314;

    // Inicializa o vetor dp com um valor muito alto (infinito)
    vector<double> dp(N + 1, 9999999);

    // Caso base: para 0 figurinhas faltando, precisamos de 0 pacotes
    dp[0] = 0;

    // Preenchendo o vetor dp
    for (int i = 1; i <= N; ++i)
    {
        // Contribuição de 5 figurinhas
        if (i >= 5)
        {
            dp[i] = min(dp[i], 1 + dp[i - 5]);
        }
        // Contribuição de 6 figurinhas
        if (i >= 6)
        {
            dp[i] = min(dp[i], 1 + dp[i - 6]);
        }
        // Contribuição de 7 figurinhas
        if (i >= 7)
        {
            dp[i] = min(dp[i], 1 + dp[i - 7]);
        }
        // Contribuição de 8 figurinhas
        if (i >= 8)
        {
            dp[i] = min(dp[i], 1 + dp[i - 8]);
        }
    }

    // Exibe o número médio de pacotes necessários para completar o álbum
    cout << "Número médio de pacotes necessários: " << dp[N] << endl;

    return 0;
}
