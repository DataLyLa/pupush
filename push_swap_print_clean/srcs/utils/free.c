#include "push_swap.h"

void	free_count(t_count *count)
{
	if (count == NULL)
		return ;
	free(count);
}

void ft_free_lst(t_list *lst)
{
    t_list  *tmp;

    if (lst)
    {
        while (lst)
        {
            tmp = lst->next;
            free(lst);
            lst = tmp;
            
        }
    }
}

void    ft_free_move(t_move *move)
{
    t_move *tmp;
    if (move)
    {
        while (move)
        {
            tmp = move;
            move = move->next;
            free(tmp);
        }
    }
}

void    ft_free_pile(t_pile *pile, int i)
{
    if (pile)
    {
        if(pile->a)
            ft_free_lst(pile->a);
        if(pile->b)
            ft_free_lst(pile->b);
        if(pile->mvt)
            ft_free_move(pile->mvt);
        free(pile);
        if (i == EXIT_FAILURE)
            exit(i);
    }
}
