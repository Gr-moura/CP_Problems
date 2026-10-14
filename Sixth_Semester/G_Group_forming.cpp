#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define pii pair<int, int>
#define pb push_back

vector<vector<int>> comp(1e5 + 10);
struct cc
{
	cc (int x) : id(x) {}

	int sz = 0, id;
	void push(int x)
	{
		comp[id].push_back(x);
		sz++;
	}

	int pop()
	{
		sz--;
		return comp[id][sz];
	}

	bool operator<(const cc &outro) const
	{
		return this->sz > outro.sz;
	}
};

vector<bool> vis (1e5 + 10, false);
vector<vector<int>> g (1e5 + 10);
void dfs(int vAtual, cc & comp)
{
	vis[vAtual] = true;
	comp.push(vAtual);

	for (auto u: g[vAtual])
		if (!vis[u]) dfs(u, comp);
}

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	multiset<cc> comp;
	int id = 0;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			cc temp(id++);
			dfs(i, temp);
			comp.insert(temp);
		}
	}

	int ans = 0;
	stringstream out;
	while(comp.size() > 1)
	{
		ans ++;
		cc um = *comp.begin();
		comp.erase(comp.begin());

		cc dois = *comp.begin();
		comp.erase(comp.begin());

		out << um.pop() << " " << dois.pop() << endl;
		if (um.sz) comp.insert(um);
		if (dois.sz) comp.insert(dois);
	}
	
	cout << ans << endl;
	cout << out.str() << endl;
	


}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}