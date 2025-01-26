#include "push_swap.h"

t_list	*ft_s_parse(t_list *lst, char *s)
{
	long int	num;
	char		*start;
	char		*end;

	num = 0;
	start = NULL;
	end = NULL;
	while (*s)
	{
		start = s;
		while (*s && *s != ' ')
			s++;
		end = s;
		if (start != end)
		{
			num = ft_atoi_len(start, end);
			if(num == LONG_MAX || !(ft_dbl_lst(num, lst) || num < INT_MIN || num > INT_MAX))
				return (ft_free_lst(lst), error_lst("Error double or overflow value"));
			ft_lst_addback(&lst, lst_init(num));
		}
		if (*s)
			s++;
	}
	return (lst);
}

t_list	*ft_lst_parse(int ac, char **av, t_list *lst)
{
	int	i;
	if (!av || lst)
		return (NULL);

	i = 1;
	while (i < ac)
	{
		if(!(lst = ft_s_parse(lst, av[i])))
			return (ft_free_lst(lst), error_lst("Error input"));
		i++;
	}
	return (lst);
}
