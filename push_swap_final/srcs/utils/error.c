#include "push_swap.h"

char	*error_str(char *s)
{
	if (s)
		ft_printf("Error\n%s\n", s);
	return (NULL);
}

int	error_int(char *s, int i)
{
	if (s)
		ft_putstr_fd("Error\n%s\n", 2);
	return (i);
}

t_list *error_lst(char *s)
{
	if (s)
		ft_putstr_fd("Error\n%s\n", 2);
	return (NULL);
}

void	error_void(char *s, t_pile *pile, int i)
{
	if (s)
		ft_printf("Error\n%s\n", s);
	ft_free_pile(pile, i);
}
