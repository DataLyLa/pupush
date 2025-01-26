#include "push_swap.h"

t_list *ft_mark(t_list *ref, t_list *last, t_list *cmp, t_list *next)
{
    printf("Current: %ld, Next: %ld\n", next->num, get_next(next)->num);
    if (next == ref)
    {
        printf("mark_ Node: %ld, Mark: %d\n", next->num, next->mark);
        return next;
    }
    if ((cmp->num < next->num) || (cmp == cmp->max && next == cmp->min))
    {
        next->mark = 0;
        printf("mark_ Node: %ld, Mark: %d\n", next->num, next->mark);
        return ft_mark(ref, cmp, next, get_next(next));
    }
    else if ((cmp->num > next->num && next->num > last->num) || (last == ref->max && next == ref->min))
    {
        if (last->mark == -1)
        {
            cmp->mark = 1;
            last->mark = 0;
        }
        else
        {
            next->mark = -1;
        }
        printf("mark_ Node: %ld, Mark: %d\n", next->num, next->mark);
        return ft_mark(ref, next, cmp, get_next(next));
    }
    else
    {
        next->mark = 1;
        printf("mark_ Node: %ld, Mark: %d\n", next->num, next->mark);
        return ft_mark(ref, last, cmp, get_next(next));
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
    ft_print_lst("-list : %ld ", lst, 'n');
    printf("\n");
    ft_print_lst("-list : %d ", lst, 'm');
    printf("\n");
    return (lst);
}

int ft_len_order(t_list *start, t_list *last, t_list *cmp, t_list *next, int len)
{
    if(next == start)
    {
        if (cmp->num > next->num)
            len += 1;
        return (len);    
    }
        
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
        print_lst_ld(lst);
        printf("\n");
        printf("n_cmp : %d\n", n_cmp);
        if(n_cmp > n_order)
        {
            n_order = n_cmp;
            ref = tmp;
        }
        n_cmp = 0;
        print_lst_ld(tmp);
        tmp = tmp->next;
        if(tmp == NULL)
            break;
    }
    printf("\nref\n");
    print_lst_ld(ref);
    printf("\n");
    lst = ft_set_mark(lst, ref);
}


void ft_find_order_minmax(t_list *lst)
{
    if(!lst)
        return ;
    ok("Enter min max order");
    lst = ft_set_mark(lst, lst->min);
    printf("\nfind order minimax");
    ft_print_lst("-list : %ld ", lst, 'n');
    printf("\n");
    ft_print_lst("-list : %d ", lst, 'm');
    printf("\n");
    printf("\nref\n");
    print_lst_ld(lst->min);
    printf("\n");
}
