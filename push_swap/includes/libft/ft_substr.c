/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:58:21 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:13:01 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	s_len;
	unsigned int	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = s_len - start;
	if (start >= s_len)
		sub_len = 0;
	if (len < sub_len)
		sub_len = len;
	d = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!d)
		return (NULL);
	(ft_memcpy(d, (s + start), sub_len));
	d[sub_len] = '\0';
	return (d);
}
