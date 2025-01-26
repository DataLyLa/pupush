/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:57:46 by lylaurol          #+#    #+#             */
/*   Updated: 2024/06/10 16:00:51 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t siz)
{
	void	*s;

	s = malloc(siz * nmemb);
	if (!s)
		return (NULL);
	ft_memset(s, 0, (nmemb * siz));
	return (s);
}
