#include "push_swap.h"

void ft_swap(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;
    tmp = (*lst)->next;
    (*lst)->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = *lst;
    tmp->prev = NULL;
    tmp->next = *lst;
    (*lst)->prev = tmp;
    *lst = tmp;
    set_first(*lst);
    set_last(*lst);
}

void ft_swap_end(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;
    tmp = *lst;
    *lst = (*lst)->next;
    (*lst)->prev = NULL;
    tmp->next = NULL;
    ft_lst_addback(lst, tmp);
    set_first(*lst);
    set_last(*lst);
}

void ft_swap_start(t_list **lst)
{
    t_list *last;

    if (!lst || !*lst || !(*lst)->next)
        return;

    last = (*lst)->last;
    last->prev->next = NULL; 
    last->prev = NULL;
    ft_lst_addfront(lst, last);
    set_first(*lst);
    set_last(*lst);
}

void ft_push(t_list **lst, t_list **lst_target)
{
    t_list *tmp;
    if(!*lst || !lst)
        return ;
    tmp = (*lst);
    (*lst)= tmp->next;
    if (*lst)
        (*lst)->prev = NULL;
    else
        *lst = NULL;
    tmp->next = NULL;
    ft_lst_addfront(lst_target, tmp);
    if (*lst != NULL)
    {
        set_first(*lst);
        set_last(*lst);
    }
}
