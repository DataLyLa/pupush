/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:54:29 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:54:33 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	int			found;
	const char	*a;

	count = 0;
	while (*s)
	{
		found = 0;
		a = accept;
		while (*a)
		{
			if (*s == *a)
			{
				found = 1;
				break ;
			}
			a++;
		}
		if (!found)
			break ;
		s++;
		count++;
	}
	return (count);
}
