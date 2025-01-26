#include "push_swap.h"

t_list *get_next(t_list *lst)
{
    if(lst == NULL)
        return (NULL);
    if(lst->next == NULL)
        return (lst->first);
    return (lst->next);
}

t_list *get_prev(t_list *lst)
{
    if(lst == NULL)
        return (NULL);
    if(lst->prev == NULL)
        return (lst->last);
    return (lst->prev);
}

t_list *get_min(t_list *lst)
{
    t_list *min;
    if(!lst)
        return (NULL);
    min = lst;
    while(lst)
    {
        if(lst->num < min->num)
            min = lst;
        lst = lst->next;
    }
    return (min);
}

t_list *get_max(t_list *lst)
{
    t_list *max;
    if(!lst)
        return (NULL);
    max = lst;
    while(lst)
    {
        if(lst->num > max->num)
            max = lst;
        lst = lst->next;
    }
    return (max);
}

int get_total(t_count *count)
{
    int total;

    total = 0;
    total += count->sa;
    total += count->sb;
    total += count->ra;
    total += count->rb;
    total += count->rr;
    total += count->rra;
    total += count->rrb;
    total += count->rrr;
    return (total);
}
