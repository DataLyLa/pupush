#include "push_swap.h"

void ft_move_b_1(t_list **mv, t_list **lst, t_move **mvt)
{
    if(!mv || !lst)
        return ;
    (*mv)->mark = 0;
    if((*mv)->count.rb != 0)
    {
        ft_do_move(ft_swap_end, lst, (*mv)->count.rb);
        ft_move_addback(mvt, move_init("rb\n", (*mv)->count.rb));
    }
    else if((*mv)->count.rrb != 0)
    {
        ft_do_move(ft_swap_start, lst, (*mv)->count.rrb);
        ft_move_addback(mvt, move_init("rrb\n", (*mv)->count.rrb));
    }
    ft_swap(lst);
    ft_move_addback(mvt, move_init("sb\n", (*mv)->count.sb));
}

void ft_move_b_2(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->rb != 0)
    {
        ft_do_move(ft_swap_end, lst, count->rb);
        ft_move_addback(mvt, move_init("rb\n", count->rb));
    }
    else if(count->rrb != 0)
    {
        ft_do_move(ft_swap_start, lst, count->rrb);
        ft_move_addback(mvt, move_init("rra\n", count->rrb));
    }
    if(count->ra != 0)
    {
        ft_do_move(ft_swap_end, lst_target, count->ra);
        ft_move_addback(mvt, move_init("ra\n", count->ra));
    }
    else if(count->rra != 0)
    {
        ft_do_move(ft_swap_start, lst_target, count->rra);
        ft_move_addback(mvt, move_init("rra\n", count->rra));
    }
    ft_push(lst, lst_target);
    if(count->pa == 1)
        ft_move_addback(mvt, move_init("pa\n", count->pa));
    else if(count->pb == 1)
       ft_move_addback(mvt, move_init("pb\n", count->pb));
}

void ft_move_b_3(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->rb != 0)
    {
        ft_do_move(ft_swap_end, lst, count->rb);
        ft_move_addback(mvt, move_init("rb\n", count->rb));
    }
    if(count->ra != 0)
    {
        ft_do_move(ft_swap_end, lst_target, count->ra);
        ft_move_addback(mvt, move_init("ra\n", count->ra));
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

void ft_move_b_4(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!count || !lst)
        return ;
    if(count->rrb != 0)
    {
        ft_do_move(ft_swap_start, lst, count->rrb);
        ft_move_addback(mvt, move_init("rrb\n", count->rrb));
    }
    if(count->rra != 0)
    {
        ft_do_move(ft_swap_start, lst_target, count->rra);
        ft_move_addback(mvt, move_init("rra\n", count->rra));
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

