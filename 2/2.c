#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int com(char str1[],char str2[]);
 
void main()
{
    char str1[50];
    char str2[50];
    gets(str1);
    gets(str2);
    printf("%d\n",com(str1,str2));
}

int com(char str1[],char str2[])
{
    int len1,len2;
    int i,j,k;
    int max=0;
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    for(i = 0; i < len1; i++)
    {
        for(j = 0; j < len2; j++)
        {
            if(str1[i] == str2[j])
            {
                for(k = 0; (str1[i+k] == str2[j+k] && str1[i+k] != '\0'); k++);
                if(max < k)
                {
                    max = k;
                }
            }
        }
    }
    return max;
}
