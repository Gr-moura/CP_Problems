#include <stdio.h>
int main()
{
    int n;
    do
    {
        printf("Tamanho: ");
        scanf("%d", &n);

    } while (n <= 0 || n > 8);

    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }

        for (int j = i; j <= n; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
