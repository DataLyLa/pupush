#include "push_swap.h"

void ft_put_move_a(t_list *move, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!move || !lst)
        return ;
    if(move->count.move == 1)
        ft_move_a_1(&move, lst, mvt);
    else if(move->count.move == 2)
        ft_move_a_2(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 3)
        ft_move_a_3(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 4)
        ft_move_a_4(&move->count, lst, lst_target, mvt);
}

void ft_put_move_b(t_list *move, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!move || !lst)
        return ;
    if(move->count.move == 1)
        ft_move_b_1(&move, lst, mvt);
    else if(move->count.move == 2)
        ft_move_b_2(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 3)
        ft_move_b_3(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 4)
        ft_move_b_4(&move->count, lst, lst_target, mvt);
}
