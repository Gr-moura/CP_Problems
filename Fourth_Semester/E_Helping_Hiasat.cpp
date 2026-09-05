/*
ID: gabriel139
LANG: C++
TASK: test
*/

/* clang-format off */
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
#include <bits/stdc++.h>
using namespace std;

// Maximum Clique
// Encontra o maior clique em um grafo não direcionado
// O(n * 2^(n/2)), onde n é o número de vértices do grafo
// Utiliza a técnica de meet-in-the-middle combinada com programação dinâmica
//
// Para encontrar o maior Conjunto Independente, basta rodar o algoritmo no grafo complemento

using ull = unsigned long long;

bool isBitSet(ull mask, ull bit)
{
    return (mask & (1ULL << bit)) != 0;
}

bool isSubset(ull subset, ull set)
{
    return (subset & set) == subset;
}

bool isClique(ull mask, ull start, ull end, const vector<ull> &adj)
{
    for (ull i = start; i <= end; i++)
    {
        if (!isBitSet(mask, i)) continue;

        // Vê se os outros bits ligados são um subconjunto dos adjacentes de i
        if (!isSubset(mask, adj[i])) return false;
    }

    return true;
}

pair<int, ull> maxClique(ull n, vector<ull> &adj)
{
    // Adiciona self-loops para facilitar a verificação de cliques
    for (int i = 0; i < n; i++)
        adj[i] |= (1ULL << i);

    ull mid = n / 2;
    ull leftSize = mid;
    ull rightSize = n - mid;

    // DP: memo[mask] armazena o melhor clique contido na máscara 'mask'
    vector<ull> memo(1ULL << leftSize);

    memo[0] = 0; // Clique vazio
    for (ull i = 1; i < (1ULL << leftSize); i++)
    {
        // Se o próprio conjunto i é um clique, ele é o melhor candidato base
        if (isClique(i, 0, mid - 1, adj))
        {
            memo[i] = i;
            continue;
        }

        // Se não é clique, a solução é a melhor solução dos subconjuntos
        // Recorrência: dp[mask] = max(dp[mask ^ (1 << j)]) para todo j setado
        ull bestSub = 0;
        for (ull j = 0; j < leftSize; j++)
        {
            if (isBitSet(i, j))
            {
                // Como a máscara (i ^ (1 << j)) é menor que i, ela já foi processada
                bestSub = max(bestSub, memo[i ^ (1ULL << j)]);
            }
        }

        memo[i] = bestSub;
    }

    ull globalBest = 0;

    // Meet-in-the-middle: Itera todos os subsets da direita
    // Intervalo [mid, n-1]
    for (ull i = 0; i < (1ULL << rightSize); i++)
    {
        ull rightPart = (i << mid);

        // Verifica se a parte da direita é válida sozinha
        if (!isClique(rightPart, mid, n - 1, adj)) continue;

        // Calcula quais nós da esquerda são compatíveis com TODOS os nós escolhidos na direita
        ull compativeisEsq = (1ULL << mid) - 1; // Máscara cheia da esquerda

        for (ull v = mid; v < n; v++)
        {
            if (isBitSet(rightPart, v))
            {
                // Intersecta com os adjacentes de v
                compativeisEsq &= adj[v];
            }
        }

        // Recupera o melhor clique possível na esquerda compatível com a direita
        ull leftPart = memo[compativeisEsq];
        ull candidate = rightPart | leftPart;

        if (__builtin_popcountll(candidate) > __builtin_popcountll(globalBest)) globalBest = candidate;
    }

    return {__builtin_popcountll(globalBest), globalBest};
}

map<string, int> idMap;
vector<ull> adj(50, ~0ULL);
set<string> addAresta;

void criaGrafoCompleto()
{
    for (auto s1 : addAresta)
    {
        int u = idMap[s1];
        for (auto s2 : addAresta)
        {
            int v = idMap[s2];
            if (u != v)
            {
                // Remove a aresta u-v
                adj[u] &= ~(1ULL << v);
                adj[v] &= ~(1ULL << u);
            }
        }
    }
}

void solve()
{
    int ev, n;
    cin >> ev >> n;

    int idCounter = 0;
    for (int i = 0; i < ev; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            criaGrafoCompleto();
            addAresta.clear();
        }

        else if (type == 2)
        {
            string nome;
            cin >> nome;

            if (idMap.find(nome) == idMap.end())
            {
                idMap[nome] = idCounter;
                idCounter++;
            }

            addAresta.insert(nome);
        }
    }

    criaGrafoCompleto();

    auto [cliqueSize, cliqueMask] = maxClique(n, adj);

    cout << cliqueSize << endl;
}

int32_t main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
