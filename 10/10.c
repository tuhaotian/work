#include <stdio.h>
#include <stdlib.h>

int s, len, max, item[100];

void a(int i, int sum)
{
    if(i >= len)
    {
        if(sum > max) max = sum;
        return;
    }
    if(item[i] + sum <= s)
        a(i + 1, sum + item[i]);
    else
        a(i + 1, sum);
}

int main()
{
    int i = 0, j = 0;
    char c;
    printf("enter the backpack size:");
    scanf("%d", &s);
    getchar();
    printf("enter the size of your items:");
    for(i = 0 ; i < 100 ; i++ )
    {
        scanf("%d" , &item[i] );
        if( (c = getchar()) == '\n') break;
    }
    len = i + 1;
    a(0, 0);
    printf("%d", max);
    return 0;
}
