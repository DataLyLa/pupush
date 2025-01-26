/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:53 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:37 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	d_len;

	if (dst == NULL && src == NULL)
		return (NULL);
	d_len = 0;
	if (dst < src)
		while (n-- > 0)
			*((char *)dst + d_len++) = *(char *)src++;
	else
		while (n-- > 0)
			*((char *)dst + n) = *(char *)(src + n);
	return (dst);
}
