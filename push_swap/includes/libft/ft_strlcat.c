/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:22:48 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:24:41 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	d_len;

	d_len = 0;
	while (d_len < siz && dst[d_len])
		d_len++;
	return (d_len + ft_strlcpy(dst + d_len, src, siz - d_len));
}
