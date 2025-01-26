/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:43:30 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:16:31 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	temp_c;

	last = NULL;
	temp_c = c;
	while (*s)
	{
		if ((unsigned char)*s == temp_c)
		last = (char *)s;
		s++;
	}
	if (temp_c == '\0')
		return ((char *)s);
	return (last);
}
