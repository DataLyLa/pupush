/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:48:20 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:30:17 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp_c;

	temp_c = c;
	while (*s && *s != temp_c)
		s++;
	if (*s == temp_c)
		return ((char *)s);
	else
		return ((char *) 0);
}
