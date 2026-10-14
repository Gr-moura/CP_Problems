/*
https://codeforces.com/contest/2259/problem/F

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

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back

// Índice base 0 do primeiro elemento maior ou igual a x em log n
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())

// Índice base 0 do primeiro elemento  estritamente maior que x em log n
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }

bool prime(ll a) { if (a <= 1) return 0; if (a == 2) return 1; if (a % 2 == 0) return 0; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */

#include <bits/stdc++.h>
using namespace std;

// Contagem de Inversões
//
// Uma inversão é um par de índices (i, j) tal que i < j e nums[i] > nums[j]
//
// O(n log n) de tempo, onde n é o número de elementos do vetor
// O(n) de memória auxiliar
//
// A contagem é feita durante o Merge Sort. Quando um elemento da metade esquerda
// é maior que o elemento atual da direita, todos os elementos seguintes a ele na parte esquerda
// também formarão uma inversão com o atual da direita

// Junta dois vetores ordenados e retorna o resultado e a quantidade de inversões
pair<vector<int>, long long> merge(const vector<int> &esq, const vector<int> &dir)
{
	int n1 = esq.size(), n2 = dir.size();

	vector<int> ord;
	int idxEsq = 0, idxDir = 0;
	long long inv = 0;

	// Escolhe o menor elemento disponível entre os dois vetores
	while (idxEsq < n1 && idxDir < n2)
	{
		if (esq[idxEsq] <= dir[idxDir]) ord.push_back(esq[idxEsq++]);
		else
		{
			ord.push_back(dir[idxDir++]);

			// O atual e todos os seguintes, do lado esquerdo, também formam uma inversão com esse da direita
			inv += n1 - idxEsq;
		}
	}

	// Copia os elementos restantes do vetor que ainda não terminou
	while (idxEsq < n1) ord.push_back(esq[idxEsq++]);
	while (idxDir < n2) ord.push_back(dir[idxDir++]);

	return {ord, inv};
}

// Retorna o vetor ordenado e sua quantidade de inversões
pair<vector<int>, long long> mergeSort(const vector<int> &nums)
{
	int n = nums.size();

	// Vetores com zero ou um elemento já estão ordenados
	if (n <= 1) return {nums, 0};

	// Divide o vetor em duas metades
	int mid = n / 2;
	vector<int> esq(nums.begin(), nums.begin() + mid);
	vector<int> dir(nums.begin() + mid, nums.end());

	// Ordena cada metade e conta suas inversões
	auto [ordEsq, invEsq] = mergeSort(esq);
	auto [ordDir, invDir] = mergeSort(dir);

	// Junta as duas metades e conta as inversões entre elas
	auto [ord, invMerge] = merge(ordEsq, ordDir);
	return {ord, invEsq + invDir + invMerge};
}

long long countInversions(const vector<int> &nums)
{
	return mergeSort(nums).second;
}

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;
	string s; cin >> s;

	vi qt(2, 0);
	for (auto i: a) qt[i]++;

	vi qtAposUm;

	vi qtZerosApos(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0) qtZerosApos[i] = qtZerosApos[i + 1] + 1;
		else qtZerosApos[i] = qtZerosApos[i + 1];
	}

	int total = countInversions(a);
	cout << total << " ";

	int tirarTudo = 0;
	for (int i = 0; i < n; i++) if (a[i]) qtAposUm.pb(qtZerosApos[i]);

	int ini = 0, fim = (int)(qtAposUm.size()) - 1;
	while (fim >= 0 and qtAposUm[fim] <= 0) fim--;
	for (int i = 0; i < n; i++)
	{
		if (ini > fim) total = 0;

		else if (s[i] == '1') total -= max(0ll, (qtAposUm[ini++] - tirarTudo));
		else 
		{
			tirarTudo++;

			total -= max(0ll, (fim - ini + 1));
			while (fim >= ini && (qtAposUm[fim] - tirarTudo <= 0)) fim--;
		}
		
		cout << max(total, 0ll) << " ";		
	}

	cout << endl;

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
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();

        // #ifdef ONPC
        //         cout << "__________________________" << endl;
        // #endif
    }

    return 0;
}
