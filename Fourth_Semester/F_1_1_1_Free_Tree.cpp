/* clang-format off */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define all(x) x.begin(), x.end()
#define sz(a) ((int)((a).size()))
#define int long long
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

bool prime(ll a) { if (a == 1) return 0; if (a == 2) return 1; for (int i = 3; i*i <= a; i+=2) if (a % i == 0) return 0; return 1; }

const int MOD = 1e9 + 7, MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
/* clang-format on */
int somaAtual = 0;

struct node
{
    int pai;
    int pesoArestaPai;
    int corAtual;

    // cor, peso
    map<int, int> pesoCores;

    node() : pai(-1), pesoArestaPai(0), corAtual(0) {}
    void print()
    {
        dbg(pai);
        dbg(pesoArestaPai);
        dbg(corAtual);
    }
};

void dfs(vector<vector<pii>> &adj, vector<node> &nodes, int pai)
{
    int corPai = nodes[pai].corAtual;
    for (auto [filho, w] : adj[pai])
    {
        // !Visitado
        if (nodes[filho].pai == -1)
        {
            nodes[filho].pai = pai;
            nodes[filho].pesoArestaPai = w;

            int corFilho = nodes[filho].corAtual;

            nodes[pai].pesoCores[corFilho] += w;
            if (corFilho != corPai) somaAtual += w;

            dfs(adj, nodes, filho);
        }
    }
}

void query(vector<node> &nodes, int atual, int novaCor)
{
    // Adicionamos a quantidade de arestas com a nossa cor antiga
    somaAtual += nodes[atual].pesoCores[nodes[atual].corAtual];
    somaAtual -= nodes[atual].pesoCores[novaCor];

    int pai = nodes[atual].pai;
    if (pai == atual)
    {
        nodes[atual].corAtual = novaCor;

        // Não precisamos atualizar a cor dos vilhos
        return;
    }

    // A quantidade de cada cor do pai precisa ser atualizada
    nodes[pai].pesoCores[nodes[atual].corAtual] -= nodes[atual].pesoArestaPai;
    nodes[pai].pesoCores[novaCor] += nodes[atual].pesoArestaPai;

    if (nodes[pai].corAtual == novaCor) somaAtual -= nodes[atual].pesoArestaPai;
    else if (nodes[pai].corAtual == nodes[atual].corAtual) somaAtual += nodes[atual].pesoArestaPai;

    nodes[atual].corAtual = novaCor;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    somaAtual = 0;

    // Resultado da query = pesoTotal - pesoArestasZeradas
    vector<node> nodes(n);
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].corAtual;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    nodes[0].pai = 0;
    dfs(adj, nodes, 0);

    for (int i = 0; i < q; i++)
    {
        int v, x;
        cin >> v >> x;
        v--;

        if (x != nodes[v].corAtual) query(nodes, v, x);
        cout << somaAtual << endl;
    }
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
