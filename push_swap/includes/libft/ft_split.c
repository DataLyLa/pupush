/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:03:35 by lylaurol          #+#    #+#             */
/*   Updated: 2024/06/08 22:25:25 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			s++;
	}
	return (word_count);
}

static int	ft_allocate(char **tab, char const *s, char sep)
{
	char const	*tmp;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (tmp > s)
		{
			tab[i] = ft_substr(s, 0, tmp - s);
			if (!tab[i])
			{
				ft_free(tab);
				return (-1);
			}
			i++;
		}
		s = tmp;
	}
	tab[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		size;

	if (!s)
		return (NULL);
	dst = NULL;
	size = ft_count_words(s, c);
	dst = (char **) malloc (sizeof (char *) * (size + 1));
	if (!dst || ft_allocate(dst, s, c) == -1)
		return (NULL);
	return (dst);
}

// int main(void)
// {
// 	char **res;
// 	res = ft_split("hello!", 32);
// 	printf("%s", res[0]);
// 	ft_free(res, 2);
// 	return 0;
// }
