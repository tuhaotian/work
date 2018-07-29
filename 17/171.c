#include "stdio.h"
#define N 100
int n, target;
int flag[100]={0};

int sum(int a[])
{
    int i, s;
    for(i = 0, s = 0; i < n; i++)
    if(flag[i])
        s = s + a[i];
    return s;
}
void find(int a[],int i)
{
    if(i >= n)
    {
        if(sum(a) == target)
        {
            printf("[");
            for(int j = 0; j < n; j++)
            if(flag[j])
                printf("%d,",a[j]);
            printf("]\n");
        }
        return ;
    }
    flag[i] = 1; find(a, i+1);
    flag[i] = 0; find(a, i+1);
}
void main()
{
    int i, j = 0;
    int a[N];
    char b[N] = {};
    getchar();
    gets(b);
    for(i = 0, j = 0 ; j < N ; j++)
    {
        if(b[j] != ',' && b[j] != ']' && b[j] != '0')
        {
            a[i] =  b[j] - '0';
            i++;
        }
        if(b[j] == '\0') break;
    }
    printf("enter the target:");
    scanf("%d", &target);
    n = i - 1;
    find(a,0);
}