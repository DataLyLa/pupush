#include "push_swap.h"

void set_min(t_list *lst)
{
    t_list *min;

    if(!lst)
        return ;
    min = get_min(lst);
    while(lst)
    {
        lst->min = min;
        lst = lst->next;
    }
}

void set_max(t_list *lst)
{
    t_list *max;

    if(!lst)
        return ;
    max = get_max(lst);
    while(lst)
    {
        lst->max = max;
        lst = lst->next;
    }
}

void set_first(t_list *lst)
{
    t_list *first;
    if(!lst)
        return ;
    first = lst;
    while(lst)
    {
        lst->first = first;
        lst = lst->next;
    }
}

void set_last(t_list *lst)
{
    t_list *last;
    if(!lst)
        return ;
    last = ft_lst_last(lst);
    while(lst)
    {
        lst->last = last;
        lst = lst->next;
    }
}
