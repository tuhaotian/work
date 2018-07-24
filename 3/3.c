#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int j = 0;
    while((a[j++] = getchar()) != '\n');
    int b = 0, c = 0, d = 0;
    int m[26];
    for (int i = 0; i < 26; i++)
        m[i] = 0;
    for (int i = 0; a[i] != '\n'; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            m[a[i] - 'a']++;
        else if(a[i] >= 'A' && a[i] <= 'Z')
            m[a[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
        b += m[i];
    printf("character number  %d\n", b);

    for (int i = 0, j = 0; a[i] != '\0';i++)
    {
        if(a[i] != ' ' && a[i] != '\n')
            j++;
        else if(j)
        {
            j = 0;
            c++;
        }
    }
    printf("words number %d\n", c);

    for (int i = 0; i < 26; i++)
    if(m[i] > d)
        d = m[i];
    
    printf("words most times:");
    for (int i = 0; i < 26; i++)
    if(m[i] == d)
        printf(" %c", 'a' + i);
    printf("\n");
    printf("times %d\n", d);
    return 0;
}