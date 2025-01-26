#include "push_swap.h"

void ft_print_move(t_move *move)
{
	t_move	*tmp;
	int i;

	tmp = move;
	
	while(tmp)
	{
		i = -1;
		while (++i < tmp->rep)
			ft_printf("%s", tmp->s);
		tmp = tmp->next;
	}
}

void ft_move_first(t_list *first, t_list **lst, t_move **mvt)
{
    if(!first || !*lst)
        return ;
    if(first->top < first->btm)
    {
        ft_do_move(ft_swap_end, lst, first->top);
        ft_move_addback(mvt, move_init("ra\n", first->top));
    }
    else
    {
        ft_do_move(ft_swap_start, lst, first->btm);
        ft_move_addback(mvt, move_init("rra\n", first->btm));
    }
}

void lst_first_place(t_pile *pile)
{
	t_list *first;
	if(!pile || !pile->a)
		return ;
	first = get_min(pile->a);
	if (first != pile->a)
	{
		get_top(&pile->a);
		get_btm(&pile->a);
		ft_move_first(first, &pile->a, &pile->mvt);
	}
}


