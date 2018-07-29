/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid. 
Input: "()[]{}"
Output: true
Input: "([)]"
Output: false
Input: "{[]}"
Output: true
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100], c[100];
    int b[6] = {0}, i, j = 0, flag = 1;
    gets(a);
    int len = strlen(a);
    if(len % 2 != 0)
    {
        printf("false\n");
        return 0;
    }
    for(i = 0 ; i < len && a[i] != '\0' ; i++)
    {
        if(a[i] == '(')
        {
          b[0]++;
          c[j++] = a[i];
        }
        if(a[i] == '[')
        {
            b[1]++;
            c[j++] = a[i];
        }
        if(a[i] == '{')
            {
               b[2]++;
               c[j++] = a[i];
            }

        if(a[i] == ')')
        {
            if(c[--j] != '(') 
                flag = 0;
            b[3]++;
        }

        if(a[i] == ']')
        {
            if(c[--j] != '[') flag = 0;
            b[4]++;
        }

        if(a[i] == '}')
        {
            if(c[--j] != '{') flag = 0;
            b[5]++;
        }
    }

    if(b[0] != b[3] || b[1] != b[4] || b[2] != b[5]) 
        flag = 0;

    if(flag == 1) 
        printf("true\n");

    else 
        printf("false\n");

    return 0;
}