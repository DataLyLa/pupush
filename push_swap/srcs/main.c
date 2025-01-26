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

void	ft_push_swap(t_pile *pile)
{
	while (!ft_mark_clean(pile->a, 0))
	{
		if(!clean_a(pile))
			return ;
		printf("\nfind_order a\n");
		ft_find_order(pile->a);	
		printf("\npost find order\n");
		ft_print_lst("-a %ld -", pile->a, 'n');
		printf("\n");  
		ft_print_lst("-m %d -", pile->a, 'm');
		printf("\n");
		ft_print_lst("-b %ld -", pile->b, 'n');
		printf("\n");  
		ft_print_lst("-m %d -", pile->b, 'm');
		printf("\n");
		printf("mouvement\n");
		ft_print_move(pile->mvt);
    	printf("\n");
	}
	printf("\npush_swap\n");
	ft_print_lst("-a %ld -", pile->a, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->a, 'm');
    printf("\n");
    ft_print_lst("-b %ld -", pile->b, 'n');
    printf("\n");  
    ft_print_lst("-m %d -", pile->b, 'm');
    printf("\n");
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
		t_list *cur = lst;
        while(cur)
        {
            printf("-%ld-", cur->num);
            cur = cur->next;
            printf("\n");
        }
		if (ft_is_sorted(lst))
			return (ft_free_lst(lst), error_int("List already sorted", EXIT_FAILURE));
		ft_find_order(lst);
		piles_init(lst, &pile);
		ft_print_lst("-list : %ld ", pile->a, 'n');
		printf("\n");
		ft_print_lst("-list : %d ", pile->a, 'm');
		printf("\n");
		if (!pile)
			return (ft_printf("pile NULL"));
		ft_push_swap(pile);
		printf("\npush_swap main\n");
		ft_print_lst("-a %ld -", pile->a, 'n');
		printf("\n");  
		ft_print_lst("-m %d -", pile->a, 'm');
		printf("\n");
		ft_print_lst("-b %ld -", pile->b, 'n');
		printf("\n");  
		ft_print_lst("-m %d -", pile->b, 'm');
		printf("\n");
		
		 t_move *cur_m = pile->mvt;
        while(cur_m)
        {
            if(cur_m == NULL)
                printf("NULL");
            else
            {
                printf(" move : %s - repeat : %d\n", cur_m->s, cur_m->rep);
                cur_m = cur_m->next;
            }
                
        }
		ft_print_move(pile->mvt);
		ft_free_pile(pile, 0);
		return (0);
	}
	else
		ft_printf("\nUSAGE : ./push_swap <more than one number>");
	return (1);
}
