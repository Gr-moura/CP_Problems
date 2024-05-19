#include <stdio.h>
int main()
{
	int vezes, qtnum, r1= 0, r2 = 0, soma = 0, num;
	scanf("%d ", &vezes);

	for (int i=0; i<vezes;i++){
        scanf("%d", &qtnum);
        r1 = 0, r2 = 0, soma = 0;
		for (int k = 0; k<qtnum; k++){
		    scanf("%d", &num);
            soma = soma + num;
            if (num%3==1){
                r1++;
            } else if (num%3==2){
                r2++;
            }
		}

		if (soma%3==0){
            printf("0\n");
            continue;
		} else if (soma%3==1 && r1 > 0){
            printf("1\n");
            continue;
		} else if (soma%3==1 && r2>1){
            printf("2\n");
            continue;
		} else {
            printf("1\n");
		}
    }
	return 0;
}

