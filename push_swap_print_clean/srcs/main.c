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

int ft_sorted_minmax(t_list *lst)
{
    t_list *current;

    if (!lst)
        return (1);

    current = lst->min;
    while (current && get_next(current) != lst->min)
    {
		if (current->num > get_next(current)->num)
            return (0);
        current = get_next(current);
	}
    return (1);
}


void	ft_push_swap(t_pile *pile)
{
	while ((!ft_mark_clean(pile->a, 0) || !ft_sorted_minmax(pile->a)))
	{
		if (ft_mark_clean(pile->a, 0) && !ft_sorted_minmax(pile->a))
		{
			ft_find_order_minmax(pile->a);
		}
		else
			ft_find_order(pile->a);
		if((!ft_mark_clean(pile->a, 0)))
		{
			if(!clean_a(pile))
			{
				return ;
			}
		}		
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
