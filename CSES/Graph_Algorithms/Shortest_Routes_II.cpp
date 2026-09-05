// Floyd-Warshall
//
// Encontra a menor distância entre quaisquer dois vértices de um grafo direcionado em O(|V|^3)
// Funciona com arestas de peso negativo, desde que não haja ciclo negativo
//
// Tempo: O(n^3), onde n é o número de vértices
// Memória: O(n^2)
//
// Definimos minDist[u][v][k] como a menor distância de u até v utilizando
// apenas os vértices 0, ..., k como intermediários
//
// O menor caminho possui duas possibilidades: ou ele não utiliza k como intermediário,
// mantendo a resposta de k - 1, ou utiliza k e é dividido em u -> k e k -> v
//
// minDist[u][v][k] = min(minDist[u][v][k - 1], minDist[u][k][k - 1] + minDist[k][v][k - 1])
//
// Antes da primeira iteração, minDist[u][v] vale 0 se u == v, o peso da aresta
// direta entre u e v caso ela exista, ou LINF caso contrário (Caso base: não há intermediário)
//
// Como minDist[u][v][k] depende apenas dos valores do nível k - 1, podemos
// eliminar a dimensão k e construir a DP de maneira bottom-up. No início da
// k-ésima iteração, minDist[u][v] representa minDist[u][v][k - 1]; ao atualizar
// a matriz, ela passa a representar minDist[u][v][k]
//
// Assim, armazenamos apenas uma matriz O(n^2), em vez da DP O(n^3) completa
//
// Os vértices são 0-indexed

#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;

const int MAXN = 510;
const int LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vi> minDist;
void floydWarshall(int nVertices)
{
	// LEMBRE DE FAZER minDist[u][v] = custo(u, v) OU LINF

	// O caminho vazio de um vértice até ele mesmo tem custo 0
	for (int u = 0; u < nVertices; u++) minDist[u][u] = 0;

	// Calcular o k necessita do k - 1, então o k é o loop mais externo
	for (int k = 0; k < nVertices; k++)
	{
		for (int u = 0; u < nVertices; u++)
		{
			// Não existe caminho u -> k, então não podemos passar por k saindo de u
			if (minDist[u][k] == LINF) continue;

			for (int v = 0; v < nVertices; v++)
			{
				// Também precisamos que o trecho k -> v exista
				if (minDist[k][v] == LINF) continue;

				// minDist[u][v][k] = min(minDist[u][v][k - 1], minDist[u][k][k - 1] + minDist[k][v][k - 1])
				minDist[u][v] = min(minDist[u][v], minDist[u][k] + minDist[k][v]);
			}
		}
	}
}

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	minDist = vector<vi> (MAXN, vi(MAXN, LINF));

	// O caminho vazio de um vértice até ele mesmo tem custo 0
	for (int v = 0; v < n; v++)
		minDist[v][v] = 0;

	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;

		// Armazena os dois sentidos e preserva a menor entre arestas paralelas
		minDist[u][v] = min(minDist[u][v], c);
		minDist[v][u] = min(minDist[v][u], c);
	}

	floydWarshall(n);

	while (q--)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;

		// LINF após o Floyd-Warshall significa que nenhum caminho existe
		if (minDist[u][v] == LINF)
			cout << -1 << '\n';
		else
			cout << minDist[u][v] << '\n';
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	return 0;
}
