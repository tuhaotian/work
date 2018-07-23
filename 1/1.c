#include<stdio.h>
int main()
{
    int m, n, i, j, c;
    int a[100] = {0}, b[100] = {0};
    scanf("%d / %d", &m, &n);
    c = m / n;
    printf("%d.", c);
    m -= c * n;
    for(i = 1; i < 100; i++)
    {
        a[m] = i;
        m *= 10;
        b[i] = m / n;
        m = m % n;
        if(m == 0)
        {
            for(j = 1; j <= i; j++)
                printf("%d", b[j]);
            break;
        }
        if(a[m] != 0)
        {
            printf("(");
            for(j = 1; j <= i; j++)
            {
                printf("%d", b[j]);
            }
            printf(")");
            break;
        }
    }
    return 0;
}