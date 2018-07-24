#include <stdio.h>
#include <stdlib.h>

struct s_list
{
    int data;
    struct s_list *next;
};


void create_list(struct s_list **head, int *p)
{
    struct s_list *loc_head = NULL, *tail;
    if(p[0] == 0);
    else
    {
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        while(*p)
        {
            tail->next = (struct s_list *)malloc(sizeof(struct s_list));
            tail = tail->next;
            tail->data = *p++;
        }
        tail->next = NULL;
    }
    *head = loc_head;
}

int main()
{
    int i, num1, num2, sum1 = 0, sum2 = 0; 
    char c;
    int a[100], b[100] ,m[100];
    for(i = 0 ; i < 100 ; i++ )
    {
        scanf("%d" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    num1 = i + 1;
    for(i = 0 ; i < 100 ; i++ )
    {
        scanf("%d" , &b[i] );
        if( (c = getchar()) == '\n') break;
    }
    num2 = i + 1;
    for(i = num1 - 1; i >= 0; i--)
    {
        sum1 = sum1 * 10 + a[i];
    }
    for(i = num2 - 1; i >= 0; i--)
    {
        sum2 = sum2 * 10 + b[i];
    }
    int sum = sum1 + sum2;
    for(i = 0 ; ; i++)
    {
        m[i] = sum % 10;
        if(sum < 10) break;
        sum /= 10;
    }

    m[i+1] = 0;
    struct s_list *head = NULL, *p;
    create_list(&head,m);
    p = head;
    printf("%d",p->data);
    while(p)
    {
        p = p->next;
        if(!p)
            break;
        printf("->%d",p->data);
    }
    printf("\n");
    return 0;
}