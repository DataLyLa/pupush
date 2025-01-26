#include "push_swap.h"

t_list *ft_find_targeta(t_list *lst, t_list *lst_target)
{
    t_list *tmp;
    t_list *closest;
    if(!lst || !lst_target)
        return (NULL);
    tmp = lst_target;
    closest = NULL;
    while(tmp)
    {
        if(lst->num < tmp->num && (!closest || tmp->num < closest->num))
            closest = tmp;
        tmp = tmp->next;
    }
    if(!closest)
        closest = get_min(lst_target);

    return (closest);
}

t_list *ft_find_targetb(t_list *lst, t_list *lst_target)
{
    t_list *tmp;
    t_list *closest;
    if(!lst || !lst_target)
        return (NULL);
    tmp = lst_target;
    closest = NULL;
    while(tmp)
    {
        if(lst->num > tmp->num && (!closest || tmp->num > closest->num))
            closest = tmp;
        tmp = tmp->next;
    }
    if(!closest)
        closest = get_max(lst_target);

    return (closest);
}

void ft_create_count(t_list *lst, t_list *lst_target, char c)
{
    t_list *tmp;
    int best_move;

    tmp = lst;
    while(tmp)
    {
        best_move = 0;
	    ft_memset(&(tmp->count), 0, sizeof(t_count));
        if(tmp->mark == -1)
            set_sa(&(tmp->count), tmp->top, tmp->btm);
        else if(tmp->mark == 1)
        {
            if(c == 'a')
                tmp->target = ft_find_targeta(tmp, lst_target);
            else
                tmp->target = ft_find_targetb(tmp, lst_target);
            if(!tmp->target)
                best_move = 0;
            else
                best_move = ft_set_best_move(tmp);
            ft_set_count(tmp, best_move, c); 
        }
        tmp = tmp->next;
    }
    lst = tmp;
}

t_list *ft_find_next_move(t_list *lst)
{
    t_list *next_to_move;
    t_list *tmp;
    tmp = lst;
    next_to_move = NULL;
    while(tmp)
    {
        if(tmp->mark != 0)
        {
            next_to_move = tmp;
            break;
        }
        tmp = tmp->next;
    }
    while(tmp)
    {  
        if(next_to_move->count.total > tmp->count.total && tmp->mark != 0)
            next_to_move = tmp;
        tmp = tmp->next;
    }
    return(next_to_move);
}
