#include "push_swap.h"

int clean_a(t_pile *pile)
{
    t_list *move;

    move = NULL;
    get_tops(pile->a, pile->b);
    get_btms(pile->a, pile->b);
    ft_create_count(pile->a, pile->b, 'b');
    move = ft_find_next_move(pile->a);
    if(!move)
        return (0);
    ft_put_move(move, &(pile->a), &(pile->b), &(pile->mvt));
    return (1);
}

int clean_b(t_pile *pile)
{
    t_list *move;

    move = NULL;
    get_tops(pile->a, pile->b);
    get_btms(pile->a, pile->b);
    ft_create_count(pile->b, pile->a, 'a');
    move = ft_find_next_move(pile->b);
    if(!move)
        return (0);
    ft_put_move(move, &(pile->b), &(pile->a), &(pile->mvt));
    return (1);
}
