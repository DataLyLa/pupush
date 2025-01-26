/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:08:58 by lylaurol          #+#    #+#             */
/*   Updated: 2025/01/22 16:52:02 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	long	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_len(n);
	num = n;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	else if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (s);
}
