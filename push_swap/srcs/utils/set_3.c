#include "push_swap.h"

void set_ra_rrb(t_count *count, int ra, int rrb, char c)
{
    count->ra = ra;
    count->rrb = rrb;
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 2;
    count->total = ra + rrb;
}

void set_rra_rb(t_count *count, int rra, int rb, char c)
{
    count->rra = rra;
    count->rb = rb;
    if(c == 'b')
        count->pb = 1;
    else if(c == 'a')
        count->pa = 1;
    count->move = 2;
    count->total = rra + rb;
}

int ft_set_best_move(t_list* lst)
{
    int tab[4];
    int find;
    int res;
    int i;
    if(!lst->target)
        return (0);
    tab[0] = max(lst->top, lst->target->top);
    tab[1] = max(lst->btm, lst->target->btm);
    tab[2] = lst->top + lst->target->btm;
    tab[3] = lst->btm + lst->target->top;
    find = tab[0];
    res = 0;
    i = 0;
    while(i < 4)
    {
        if(tab[i] < find)
        {
            find = tab[i];
            res = i;
        }
        i++;
    }
    return (res + 1);
}

void ft_set_count(t_list *lst, int best_move, char c)
{
    if(best_move == 0 && c == 'b')
        set_ra_rra(&(lst->count), lst->top, lst->btm, c);
    else if(best_move == 0 && c == 'a')
        set_rb_rrb(&(lst->count), lst->top, lst->btm, c);
    else if(best_move == 1)
        set_rr(&(lst->count), lst->top, lst->target->top, c);
    else if(best_move == 2)
        set_rrr(&(lst->count), lst->btm, lst->target->btm, c);
    else if(best_move == 3)
        set_ra_rrb(&(lst->count), lst->top, lst->target->btm, c);
    else if(best_move == 4)
        set_rra_rb(&(lst->count), lst->btm, lst->target->top, c);
}

