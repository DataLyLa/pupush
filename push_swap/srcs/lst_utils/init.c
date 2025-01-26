/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:30:59 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 20:33:56 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_init(long int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->mark = 0;
	new->top = 0;
	new->btm = 0;
	ft_memset(&(new->count), 0, sizeof(t_count));
	new->target = NULL;
	new->min = NULL;
	new->max = NULL;
	new->first = NULL;
	new->last = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_move	*move_init(char *s, int n)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	new->s = s;
	new->rep = n;
	new->next = NULL;
	return (new);
}

void	piles_init(t_list *lst, t_pile **pile)
{
	if (!lst)
		return ;
	*pile = (t_pile*)malloc(sizeof(t_pile));
	if (!*pile)
		return (ft_free_lst(lst), free(pile), exit(EXIT_FAILURE));
	(*pile)->a = lst;
	(*pile)->b = NULL;
	(*pile)->mvt = NULL;
	if (!(*pile)->a)
		return (error_void("Error fail to allocate piles memory", *pile, EXIT_FAILURE));
}
