/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:33:12 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:39:12 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	dst_len;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	dst_len = 0;
	if (dst < src || dst >= src + n)
		while (n-- > 0)
			*((char *)dst + dst_len++) = *((char *)src++);
	return (dst);
}
