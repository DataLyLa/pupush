#include "push_swap.h"

int max(int a, int b)
{
    if(a < b)
        return (b);
    return(a);
}

void get_top(t_list **lst)
{
    int i;
    t_list *tmp;
    if(!*lst || !lst)
        return ;
    i = 0;
    tmp = *lst;
    while(tmp)
    {
        tmp->top = i;
        i++;
        tmp = tmp->next;
    }      
}

void get_tops(t_list *lst_a, t_list *lst_b)
{
    get_top(&lst_a);
    get_top(&lst_b);
}

void get_btm(t_list **lst)
{
    int i;
    t_list *tmp;
    if(!*lst || !lst)
        return ;
    i = 1;
    tmp = ft_lst_last(*lst);
    while(tmp)
    {
        tmp->btm = i;
        i++;
        tmp = tmp->prev;
    }
}

void get_btms(t_list *lst_a, t_list *lst_b)
{
    get_btm(&lst_a);
    get_btm(&lst_b);
}