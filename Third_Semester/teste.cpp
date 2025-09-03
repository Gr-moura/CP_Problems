#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a = 0;
	int lado = 8;
	for (int i = 2; i < 10000000; i++)
	{
		a += lado + 1;
		if (a % (4 * lado) == 0)
		{
			cout << i;
			break;
		}
	}
}