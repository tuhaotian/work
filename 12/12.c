#include <stdio.h>
#include <string.h>

int main()
{
    char a[10000], b[10000], m[10000];
    int i,j;
    char c;
    gets(a);
    int len = strlen(a);
    strcpy(b, a);
    for(i = 0, j = 0; a[i] != '\0'; i++)
    {
        if(a[i] == ' ')
        {
            m[j] = i;
            j++;
        }
    }
    len += j * 2;
    int n = j, x, t;
    for(j = 0; j < n; j++)
    {
        x = m[j];
        t = x + j * 2;
        b[t] = '%';
        b[t + 1] = '2';
        b[t + 2] = '0';
        for(; a[x + 1] != '\0'; t++, x++)
            b[t + 3] = a[x + 1];
    }
    puts(b);
    printf("%d\n", len);
    return 0;
}
