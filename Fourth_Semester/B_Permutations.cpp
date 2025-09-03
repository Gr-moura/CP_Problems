/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int int
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define lb(vect, x) (lower_bound(all(vect), x) - vect.begin())
#define ub(vect, x) (upper_bound(all(vect), x) - vect.begin())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i*i <= a; i++) if (a % i == 0) return 0; return 1; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<int> original;
vector<int> vetor;
vector<int> permutacao;

int findDiff()
{
	int maior = vetor[0];
	for (int i = 1; i < n; i++)
	{
		if (vetor[i] > maior)
			maior = vetor[i];
	}
	
	int menor = vetor[0];
	for (int i = 1; i < n; i++)
	{
		if (vetor[i] < menor)
			menor = vetor[i];
	}
	return maior - menor;
}

int digito (int num, int pos)
{
	int digito = (num / (int)pow(10, k - pos - 1) ) % 10;
	return digito;
}

void applyPermutation()
{
    for (int i = 0; i < n; i++)
    {
		vetor[i] = 0;
        for (int j = 0; j < k; j++)
		{
			vetor[i] += digito(original[i], permutacao[j]) * (int) pow(10, k - j - 1);
		}
    }
}

/* clang-format on */
void solve()
{
    cin >> n >> k;

    vetor.resize(n);
    original.resize(n);
    permutacao.resize(k);

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
    }

    for (int i = 0; i < k; i++)
        permutacao[i] = i;

    int smallDiff = -1;

    do
    {
        applyPermutation();

        int diff = findDiff();

        if (smallDiff == -1 || diff < smallDiff) smallDiff = diff;
    } while (next_permutation(all(permutacao)));

    cout << smallDiff << endl;
}

int32_t main()
{
    // casas decimais
    // cout << fixed << setprecision(1);

    // horario
    // cout << setfill('0') << setw(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
