#include <stdio.h>

int main()
{
    int x = 0, k = 3, n, i;
    scanf("%d", &n);
    while(x != n)
    {
        i = k;
        while(i % 5 == 0)
            i = i / 5;
        while(i % 3 == 0)
            i = i / 3;
        while(i % 7 == 0)
            i = i / 7;
        if(i == 1)
            x++;
        k++;
    }
    printf("%d\n", k - 1);
    return 0;
}