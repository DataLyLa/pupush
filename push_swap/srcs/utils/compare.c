#include "push_swap.h"

long int ft_atoi_len(char *start, char *end)
{
    long int n;
    int sign;

    n = 0;
    sign = 1;
    if (*start == '+' || *start == '-')
    {
        if(*start == '-')
            sign = -1;
        start++;
    }
    while(start < end && ft_isdigit(*start))
    {
        n = n * 10 + (*start++ - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && -n < INT_MIN))
            return (LONG_MAX);
    }
    if(start < end && !ft_isdigit(*start))
        return (LONG_MAX);
    return (n * sign);
}

int	ft_is_sorted(t_list *lst)
{
	if(!lst)
		return (0);
	while(lst && lst->next)
	{
		if(lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_dbl_lst(int n, t_list *lst)
{
	while (lst)
	{
		if(n == lst->num)
			return (0);
		lst =lst->next;
	}
	return (1);
}

int ft_mark_clean(t_list *lst, int n)
{
    t_list *tmp;
    if(!lst)
        return (1);
    tmp = lst;
    while(tmp)
    {
        if(tmp->mark != n)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int ft_abs(int n)
{
    if(n < 0)
        return (-n);
    return (n);
}
