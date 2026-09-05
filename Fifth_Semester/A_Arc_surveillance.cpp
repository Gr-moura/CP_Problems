#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()
typedef vector<int> vi;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &i: a) cin  >> i; 

	sort(all(a));

	int ans = 500;
	for (int i = 0; i < n; i++)
	{
		int opt1 = a[i] - a[(i + 1) % n];
		if (opt1 < 0) opt1 += 360;
		
		ans = min (ans, opt1);
	}

	cout << ans + 1 << endl;

}

int main()
{
	solve();
	return 0;
}

