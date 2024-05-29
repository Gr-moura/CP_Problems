#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
	int a, b, l, vezes, expmax_a = 0, expmax_b = 0, count = 0, pot;
	scanf("%d ", &vezes);
	double temp;
	set <int> s;


	for (int i=0; i<vezes;i++){
		scanf("%d %d %d ", &a, &b, &l);

		temp = (double)l;
		while (temp/a>=1){
			expmax_a ++;
			temp = temp /(double)a;
		}
		temp = (double)l;
		while (temp/b>=1){
			expmax_b ++;
			temp = temp /(double)b;
		}
		for (int k = 0; k<=expmax_b; k++){
			for (int j = 0; j<=expmax_a; j++){
                pot=(int)(pow(b,k)*pow(a,j));
				if (pot<= l && l%pot==0 && s.find(pot)==s.end()){
                    s.insert(pot);
					count++;
				}
			}
		}
		printf("%d\n", count);
		s.clear();
		count = 0;
		expmax_a = 0;
		expmax_b = 0;
	}
	return 0;
}
