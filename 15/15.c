#include <stdio.h>
#include <stdlib.h>

char s1[100], s2[100], s3[100];
int flag;

void interleaving(int k1, int k2, int k3)
{
    if(s3[k3] == '\0')
    {
        if(s1[k1] == '\0' && s2[k2] == '\0') 
            flag = 1;
        return;
    }
    if(s3[k3] == s1[k1]) 
        interleaving(k1 + 1, k2, k3 + 1);
    if(s3[k3] == s2[k2]) 
        interleaving(k1, k2 + 1, k3 + 1);
}

int main()
{
    gets(s1);
    gets(s2);
    gets(s3);
    interleaving(0, 0, 0);

    if(flag == 1) 
        printf("ture\n");
    else 
        printf("flase\n");
    return 0;
}
