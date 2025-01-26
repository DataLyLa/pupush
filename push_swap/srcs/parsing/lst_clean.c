#include "push_swap.h"

t_list *ft_find_targeta(t_list *lst, t_list *lst_target)
{
    t_list *tmp;
    t_list *closest;
    if(!lst || !lst_target)
        return (NULL);
    tmp = lst_target;
    closest = NULL;
    printf("\ntarget a\n");
    ft_print_lst("-a %ld -", lst, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", lst, 'm');
    printf("\n");  
    lst_target ? ft_print_lst("-b %ld -", lst_target, 'n') : printf("NULL");
    printf("\n");
    lst_target ? ft_print_lst("-m %d -", lst_target, 'm') : printf("NULL");
    printf("\n\n");
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
    printf("\ntarget b\n");
    ft_print_lst("-a %ld -", lst, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", lst, 'm');
    printf("\n");  
    lst_target ? ft_print_lst("-b %ld -", lst_target, 'n') : printf("NULL");
    printf("\n");
    lst_target ? ft_print_lst("-m %d -", lst_target, 'm') : printf("NULL");
    printf("\n\n");
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
            if (c == 'a')
                ft_set_count_b(tmp, best_move, c);
            else
                ft_set_count_a(tmp, best_move, c);
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
    printf("next to move : %ld\n", next_to_move->num);
    while(tmp)
    {  
        if(next_to_move->count.total > tmp->count.total && tmp->mark != 0)
            next_to_move = tmp;
        tmp = tmp->next;
    }
    printf("next to move : %ld\n", next_to_move->num);
    return(next_to_move);
}

int clean_a(t_pile *pile)
{
    t_list *move;

    move = NULL;
    get_tops(pile->a, pile->b);
    get_btms(pile->a, pile->b);
        printf("first lst top : %d, first lst_targert top : %d\n", pile->a->first->top, pile->b? pile->b->first->top : 99);
        printf("last lst top : %d, last lst_targert top : %d\n", pile->a->last->top, pile->b? pile->b->last->top : 99);
        printf("first lst btm : %d, first lst_targert btm : %d\n", pile->a->first->btm, pile->b? pile->b->first->btm : 99);
        printf("last lst btm : %d, last lst_targert btm : %d\n", pile->a->last->btm, pile->b? pile->b->last->btm : 99);
    ft_create_count(pile->a, pile->b, 'b');
    move = ft_find_next_move(pile->a);
    if(!move)
        return (0);
    printf("\nmove clean a : %ld\n", move->num);
    printf("move mark  : %d  ", move->mark);
    printf("ra : %d  ", move->count.ra);
    printf("rra : %d  ", move->count.rra);
    printf("rb : %d  ", move->count.rb);
    printf("rrb : %d  ", move->count.rrb);
    printf("rr : %d  ", move->count.rr);
    printf("rrr : %d  ", move->count.rrr);
    printf("sa : %d  ", move->count.sa);
    printf("pb : %d  ", move->count.pb);
    printf("pa : %d  ", move->count.pa);
    printf("total : %d  ", move->count.total);
    printf("\nmove  count clean a : %d\n", move->count.move);
    ft_put_move_a(move, &(pile->a), &(pile->b), &(pile->mvt));
    ft_print_lst("-a %ld -", pile->a, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->a, 'm');
    printf("\n");
    ft_print_lst("-b %ld -", pile->b, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->b, 'm');
    printf("\n");  
    return (1);
}

int clean_b(t_pile *pile)
{
    t_list *move;

    move = NULL;
    get_tops(pile->a, pile->b);
    get_btms(pile->a, pile->b);
        printf("first lst top : %d, first lst_targert top : %d\n", pile->a->first->top, pile->b? pile->b->first->top : 99);
        printf("last lst top : %d, last lst_targert top : %d\n", pile->a->last->top, pile->b? pile->b->last->top : 99);
        printf("first lst btm : %d, first lst_targert btm : %d\n", pile->a->first->btm, pile->b? pile->b->first->btm : 99);
        printf("last lst btm : %d, last lst_targert btm : %d\n", pile->a->last->btm, pile->b? pile->b->last->btm : 99);
    ft_create_count(pile->b, pile->a, 'a');
    move = ft_find_next_move(pile->b);
    if(!move)
        return (0);
    printf("\nmove clean a : %ld\n", move->num);
    printf("move mark  : %d  ", move->mark);
    printf("ra : %d  ", move->count.ra);
    printf("rra : %d  ", move->count.rra);
    printf("sa : %d  ", move->count.sa);
    printf("pb : %d  ", move->count.pb);
    printf("pa : %d  ", move->count.pa);
    printf("total : %d  ", move->count.total);
    printf("\nmove  count clean a : %d\n", move->count.move);
    ft_put_move_b(move, &(pile->b), &(pile->a), &(pile->mvt));
    ft_print_lst("-a %ld -", pile->a, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->a, 'm');
    printf("\n");
    ft_print_lst("-b %ld -", pile->b, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->b, 'm');
    printf("\n");  
    return (1);
}
