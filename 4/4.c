#include <stdio.h>
#include <string.h>

 void reset(char a[], int b, int c)
 {
     int i = b, j = c;
     for (; i < j; i++,j--)
     {
         char d = a[i];
         a[i] = a[j];
         a[j] = d;
     }
 }

int main()
{
    char a[100];
    int b = 0, n;
    char c;
    for (; (c = getchar()) != '\n'; b++)
    {
        a[b] = c;
    }
    a[b + 1] = '\0';
    n = strlen(a) - 1;
    reset(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != '\0' && a[i] != ' ')
        {
            int j = i;
            while (a[j] != '\0' && a[j] != ' ' && j < n)
                j++;
            j--;
            reset(a, i, j);
            i = j + 1;
        }
    }
    a[n] = '\0';
    printf("%s", a);
    return 0;
 }
