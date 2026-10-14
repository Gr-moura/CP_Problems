#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << " ## " << endl

char ask(int psize, int l)
{
    cout << "? " << psize << " ";
    for (int i = l; i < l + 2 * psize; i++) cout << i << " ";
    cout << endl;
    cout.flush();

    char ans;
    cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    int psize = (n + 2) / 3;
    int l = 1;

    while(psize >= 1)
    {
        char c = ask(psize, l);

        if (c == 'I')
        {
            l = l + 2 * psize;
            n = n - l + 1;
            psize = (n + 2) / 3;			
        }

        else if (c == 'E')
        {
            l = l;
            n = psize;
            psize = (n + 2) / 3;
        }

        else
        {
            l = l + psize;
            n = psize;
            psize = (n + 2) / 3;
        }

		if (n <= 2) break;
    }

	if (n == 2)
	{
		char c = ask(1, l);
		if (c == 'D')
		{
			cout << "! " << l + 1 << endl;
			cout.flush();

			return;
		}

	}

    cout << "! " << l << endl;
    cout.flush();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}