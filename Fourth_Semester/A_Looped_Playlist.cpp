#include <iostream>
#include <numeric>
#include <vector>

// Usar long long para evitar overflow com 'p' e a soma
using ll = long long;

// Constante para representar "infinito"
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve()
{
    int n;
    ll p;
    std::cin >> n >> p;

    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    ll min_total_songs = LINF;
    int best_start_idx = -1;

    // 1. Loop Externo: Itera por cada música como um possível ponto de partida.
    for (int i = 0; i < n; ++i)
    {
        // Para cada ponto de partida 'i', simula o processo.
        ll current_sum = 0;
        int songs_played = 0;

        // 2. Loop Interno: Simula a playlist.
        // O limite j < 2*n é um teto razoável para problemas onde p não é gigante.
        // Para p muito grande, este loop seria a causa do TLE (Time Limit Exceeded).
        for (int j = 0;; ++j)
        {
            int current_idx = (i + j) % n; // Garante que a playlist seja circular

            current_sum += a[current_idx];
            songs_played++;

            // 3. Verificação: Atingiu o objetivo?
            if (current_sum >= p)
            {
                // Se o número de músicas para esta partida é o menor já visto...
                if (songs_played < min_total_songs)
                {
                    min_total_songs = songs_played;
                    best_start_idx = i + 1; // Armazena o índice 1-based
                }
                // Encontramos a solução para este ponto de partida 'i',
                // então podemos parar de simular e ir para o próximo 'i'.
                break;
            }
        }
    }

    // 4. Resultado
    std::cout << best_start_idx << " " << min_total_songs << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}