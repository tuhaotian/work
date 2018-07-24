#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int a[6], sum[6];
    int i, j, s, m, n, min, N = 5;
    sum[0] = 0;
    for(i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= N; i++)
        sum[i] = a[i] + sum[i-1];
    
    min = a[1];
    m = 1; n = 1;
    for(i = 1; i <= N; i++)
    {
        for(j = i; j <= N; j++)
        {
            s = sum[j] - sum[i-1];
            if(abs(s) < abs(min))
            {
                min = s;
                m = i;
                n = j;
            }
        }
    }
    for(i = 1; i < N; i++)
    {
        for(j = i; j <= N; j++)
        {
            s = sum[j] - sum[i-1];
            if(abs(s) == abs(min))
                printf("[%d,%d]", i-1, j-1);
        }
    }
    printf("or[%d,%d]",m-1, n-1);
    return 0;
}