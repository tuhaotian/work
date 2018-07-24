#include <stdlib.h>
#include <stdio.h>

struct s_list
{
    int a;
    struct s_list *next;
};

int main()
{
    int a, c;
    struct s_list *head = NULL, *p;
    c = scanf("%d", &a);
    if(c != EOF)
    {
        head = (struct s_list *)malloc(sizeof(struct s_list));
        head->a = a;
        p = head;
        while(c != EOF)
        {
            p->next = (struct s_list *)malloc(sizeof(struct s_list));
            p = p->next;
            p->a = a;
        }
        p->next = NULL;
    }
    p = head;

    while(p != NULL)
    {
        struct s_list *m = (struct s_list *)malloc(sizeof(struct s_list));
        struct s_list *n = (struct s_list *)malloc(sizeof(struct s_list));
        m = head;
        n->next = m;
        while(m != NULL)
        if(m->a == p->a && m != p)
        {
            n->next = n->next->next;
            m = m->next;
        }
        else
        {
            n = n->next;
            m = m->next;
        }
        p = p->next;
    }
    p = head;
    while(p!=0)
    {
        printf("%d ", p->a);
        p = p->next;
    }
    return 0;
}