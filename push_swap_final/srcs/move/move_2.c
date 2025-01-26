#include "push_swap.h"

void ft_do_move(void (*f)(t_list **), t_list **arg, int n)
{
    int i;
    if(!f || n <= 0)
        return;
    i = 0;
    while(i < n)
    {
        f(arg);
        i++;
    }
}

void ft_move_1(t_list **mv, t_list **lst, t_move **mvt)
{
    if(!mv || !lst)
        return ;
    (*mv)->mark = 0;
    if((*mv)->count.ra != 0)
    {
        ft_do_move(ft_swap_end, lst, (*mv)->count.ra);
        ft_move_addback(mvt, move_init("ra\n", (*mv)->count.ra));
    }
    else if((*mv)->count.rra != 0)
    {
        ft_do_move(ft_swap_start, lst, (*mv)->count.rra);
        ft_move_addback(mvt, move_init("rra\n", (*mv)->count.rra));
    }
    ft_swap(lst);
    ft_move_addback(mvt, move_init("sa\n", (*mv)->count.sa));
}

void ft_move_2(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->ra != 0)
    {
        ft_do_move(ft_swap_end, lst, count->ra);
        ft_move_addback(mvt, move_init("ra\n", count->ra));
    }
    else if(count->rra != 0)
    {
        ft_do_move(ft_swap_start, lst, count->rra);
        ft_move_addback(mvt, move_init("rra\n", count->rra));
    }
    if(count->rb != 0)
    {
        ft_do_move(ft_swap_end, lst_target, count->rb);
        ft_move_addback(mvt, move_init("rb\n", count->rb));
    }
    else if(count->rrb != 0)
    {
        ft_do_move(ft_swap_start, lst_target, count->rrb);
        ft_move_addback(mvt, move_init("rrb\n", count->rrb));
    }
    ft_push(lst, lst_target);
    if(count->pa == 1)
        ft_move_addback(mvt, move_init("pa\n", count->pa));
    else if(count->pb == 1)
       ft_move_addback(mvt, move_init("pb\n", count->pb));
}

void ft_move_3(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->ra != 0)
    {
        ft_do_move(ft_swap_end, lst, count->ra);
        ft_move_addback(mvt, move_init("ra\n", count->ra));
    }
    if(count->rb != 0)
    {
        ft_do_move(ft_swap_end, lst_target, count->rb);
        ft_move_addback(mvt, move_init("rb\n", count->rb));
    }
    if(count->rr != 0)
    {
        ft_do_move(ft_swap_end, lst, count->rr);
        ft_do_move(ft_swap_end, lst_target, count->rr);
        ft_move_addback(mvt, move_init("rr\n", count->rr));
    }
    ft_push(lst, lst_target);
    if(count->pa == 1)
        ft_move_addback(mvt, move_init("pa\n", count->pa));
    else if(count->pb == 1)
       ft_move_addback(mvt, move_init("pb\n", count->pb));

}

void ft_move_4(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->rra != 0)
    {
        ft_do_move(ft_swap_start, lst, count->rra);
        ft_move_addback(mvt, move_init("rra\n", count->rra));
    }
    if(count->rrb != 0)
    {
        ft_do_move(ft_swap_start, lst_target, count->rrb);
        ft_move_addback(mvt, move_init("rrb\n", count->rrb));
    }
    if(count->rrr != 0)
    {
        ft_do_move(ft_swap_start, lst, count->rrr);
        ft_do_move(ft_swap_start, lst_target, count->rrr);
        ft_move_addback(mvt, move_init("rrr\n", count->rrr));
    }
    ft_push(lst, lst_target);
    if(count->pa == 1)
        ft_move_addback(mvt, move_init("pa\n", count->pa));
    else if(count->pb == 1)
       ft_move_addback(mvt, move_init("pb\n", count->pb));

}
