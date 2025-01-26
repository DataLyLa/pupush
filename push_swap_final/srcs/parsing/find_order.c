#include "push_swap.h"

t_list *ft_mark(t_list *ref, t_list *last, t_list *cmp, t_list *next)
{
    if (next == ref)
        return (next);
    if ((cmp->num < next->num) || (cmp == ref->max && next == ref->min))
    {
        next->mark = 0;
        return (ft_mark(ref, cmp, next, get_next(next)));
    }
    else if ((cmp->num > next->num && next->num > last->num) || (last == ref->max && next == ref->min))
    {
        if (last->mark == -1)
        {
            next->mark = 1;
            last->mark = 0;
        }
        else
            next->mark = -1;
        return (ft_mark(ref, next, cmp, get_next(next)));
    }
    else
    {
        next->mark = 1;
        return (ft_mark(ref, last, cmp, get_next(next)));
    }
}


t_list *ft_set_mark(t_list *lst, t_list *ref)
{
    t_list *tmp;
    if(!lst ||!ref)
        return NULL;
    tmp = lst;
    while(tmp != ref)
    {
        tmp = tmp->next;
    }
    tmp = ft_mark(ref, get_prev(ref), ref, get_next(ref));
    return (lst);
}

int ft_len_order(t_list *start, t_list *last, t_list *cmp, t_list *next, int len)
{
    if(next == start)
        return (len);
    if((cmp->num < next->num) || (cmp == start->max && next == start->min))
        return (ft_len_order(start, cmp, next, get_next(next), len + 1));
    else if((cmp->num > next->num && next->num > last->num) || (last == start->max && next == start->min))
    {
        if(last == next->prev)
            return ft_len_order(start, last, cmp, get_next(next), len);
        else
            return (ft_len_order(start, next, cmp, get_next(next), len + 1));
    }
    else
        return ft_len_order(start, last, cmp, get_next(next), len);
}

void ft_find_order(t_list *lst)
{
    t_list *tmp;
    t_list *ref;
    int n_order;
    int n_cmp;

    if(!lst)
        return ;
    ref = NULL;
    tmp = lst;
    n_cmp = 0;
    n_order = 0;
    while(tmp->next != tmp)
    {
        n_cmp = ft_len_order(tmp, tmp->last, tmp, get_next(tmp), n_cmp);
        if(n_cmp > n_order)
        {
            n_order = n_cmp;
            ref = tmp;
        }
        n_cmp = 0;
        tmp = tmp->next;
        if(tmp == NULL)
            break;
    }
    lst = ft_set_mark(lst, ref);
}
