/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:31:49 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:24:13 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = 0;
	if (siz)
	{
		while (*src && d_len < siz - 1)
			dst[d_len++] = *src++;
		if (d_len < siz)
			*(dst + d_len) = '\0';
	}
	return (s_len);
}
