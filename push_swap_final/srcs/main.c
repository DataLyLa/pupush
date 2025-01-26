#include "push_swap.h"

void	ft_push_swap(t_pile *pile)
{
	while (!ft_mark_clean(pile->a, 0))
	{
		if(!clean_a(pile))
			return ;
		ft_find_order(pile->a);	
	}
	while(pile->b)
	{
		if (!clean_b(pile))
			return;
	}
	lst_first_place(pile);
}

int main(int ac, char **av)
{
	t_pile	*pile;
	t_list	*lst;

	if (ac > 2)
	{
		lst = NULL;
		pile = NULL;
		lst = ft_lst_parse(ac, av, lst);
		if (!lst)
			return (ft_free_lst(lst), error_int("Problem creating stack a", EXIT_FAILURE));
		if (ft_is_sorted(lst))
			return (ft_free_lst(lst), error_int("List already sorted", EXIT_FAILURE));
		ft_find_order(lst);
		piles_init(lst, &pile);
		if (!pile)
			return (ft_printf("pile NULL"));
		ft_push_swap(pile);
		ft_print_move(pile->mvt);
		ft_free_pile(pile, 0);
		return (0);
	}
	else
		ft_printf("\nUSAGE : ./push_swap <more than one number>");
	return (1);
}
