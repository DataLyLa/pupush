#include "push_swap.h"

void ft_put_move(t_list *move, t_list **lst, t_list **lst_target, t_move **mvt)
{
    if(!move || !lst)
        return ;
    if(move->count.move == 1)
        ft_move_1(&move, lst, mvt);
    else if(move->count.move == 2)
        ft_move_2(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 3)
        ft_move_3(&move->count, lst, lst_target, mvt);
    else if(move->count.move == 4)
        ft_move_4(&move->count, lst, lst_target, mvt);
}
