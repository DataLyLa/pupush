#include "push_swap.h"

void ft_lst_addback(t_list **lst, t_list *new)
{
    t_list *last;
    if(!new)
        return ;
    if(!*lst)
    {
        *lst = new;
    }
    else
    {
        last = ft_lst_last(*lst);
        last->next = new;
        new->prev = last;
    }
    set_min(*lst);
    set_max(*lst);
    set_first(*lst);
    set_last(*lst);
}

void ft_move_addback(t_move **mv, t_move *new)
{
    t_move *last;
    if(!new)
        return ;
    if(!*mv)
    {
        *mv = new;
    }
    else
    {
        last = *mv;
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

void ft_lst_addfront(t_list **lst, t_list *new)
{
    if (!new)
        return;
    if (new->next != NULL)
        new->prev = NULL;
    if (*lst) 
        (*lst)->prev = new;
    new->next = *lst;
    *lst = new;
    set_min(*lst);
    set_max(*lst);
    set_first(*lst);
    set_last(*lst);
}

t_list *ft_lst_last(t_list* lst)
{
    if(!lst)
        return (NULL);
    while(lst->next)
        lst =lst->next;
    return (lst);
}

t_move *ft_move_last(t_move *mv)
{
    if(!mv)
        return (NULL);
    while(mv->next)
        mv = mv->next;
    return (mv);
}
