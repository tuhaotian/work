/*Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
For numbers [1,2,2] the unique permutations are:

[

    [1,2,2],

    [2,1,2],

    [2,2,1]

]
不使用递归
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int *a,int n)
{
    int i, j, t, k;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(*(a+j) > *(a+j+1))
                t = *(a+j), *(a+j) = *(a+j+1), *(a+j+1) = t;
}

int p(int a[], int len)
{
    if(len == 0 || len == 1)
        return 0;
    int m = 0, i = len - 1, j = len;
    while(i > 0 && a[i-1] >= a[i])
        i--;
    if(i)
        i--;
    while(j--)
        if(a[j]>a[i])
        {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            m = 1;
            break;
        }
    i++;
    len--;
    for (; i < len; i++, len--)
    {
        int t = a[i];
        a[i] = a[len];
        a[len] = t;
    }
    return m;
}

int main()
{
    int a[20], len, i;
    char c;
    for(i = 0 ; i < 100 ; i++ )
    {
        scanf("%d" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    len = i + 1;
    sort(a, len - 1);
    do{
        for (i = 0; i < len; i++)
            printf("%d ", a[i]);
        putchar('\n');
    } 
    while (p(a, len));
    return 0;
}



