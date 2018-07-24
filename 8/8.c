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
    int i, j, x, n; char c;
    int a[100] ;
    for(i = 0 ; i < 100 ; i++ )
    {
        scanf("%d" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    n = i + 1;
    printf("enter value x:");
    scanf("%d", &x);
    int b[n];
    for(i = 0, j = 0 ; i < n ;i++)
    {
        if(a[i] < x)
        {
            b[j] = a[i];
            j++;
        }
    }
    for(i = n - 1 , j = n - 1 ; i >= 0 ;i--)
    {
        if(a[i] >= x)
        {
            b[j] = a[i];
            j--;
        }
    }
    b[n] = 0;
    struct s_list *head = NULL, *p;
    create_list(&head,b);
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