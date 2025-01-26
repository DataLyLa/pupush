#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_count
{
	int	move;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pb;
	int	pa;
	int	total;
}		t_count;

typedef struct s_move
{
	char            *s;
	int             rep;
	struct s_move  *next;
}           t_move;

typedef struct s_list
{
	long int	    num;
	int			    mark;
	int			    top;
	int			    btm;
	struct s_list	*target;
	t_count		    count;
	int		len;
	struct s_list	*min;
	struct s_list	*max;
	struct s_list	*first;
	struct s_list	*last;
	struct s_list	*prev;
	struct s_list	*next;
}				    t_list;

typedef struct s_pile
{
	t_list	*a;
	t_list	*b;
	t_move  *mvt;
}			t_pile;

t_list	*ft_s_parse(t_list *lst, char *s);
t_list	*ft_lst_parse(int ac, char **av, t_list *lst);
int		ft_is_sorted(t_list *lst);
int		ft_dbl_lst(int n, t_list *lst);
long int		ft_atoi_len(char *start, char *end);

void	ft_push_swap(t_pile *pile);

void	piles_init(t_list *lst, t_pile **pile);
t_move	*move_init(char *s, int n);
t_list	*lst_init(long int num);

void ft_lst_addback(t_list **lst, t_list *new);
void ft_move_addback(t_move **mv, t_move *new);
void ft_lst_addfront(t_list **lst, t_list *new);
t_list *ft_lst_last(t_list* lst);
t_move *ft_move_last(t_move *mv);

void get_top(t_list **lst);
void get_btm(t_list **lst);
void get_tops(t_list *lst_a, t_list *lst_b);
void get_btms(t_list *lst_a, t_list *lst_b);
int max(int a, int b);

t_list	*get_next(t_list *lst);
t_list	*get_prev(t_list *lst);
t_list	*get_min(t_list *lst);
t_list	*get_max(t_list *lst);
int		get_total(t_count *count);

void	set_first(t_list *lst);
void	set_last(t_list *lst);
void	set_min(t_list *lst);
void	set_max(t_list *lst);
void set_sa(t_count *count, int ra, int rra);
void set_rr(t_count *count, int ra, int rb, char c);
void set_rrr(t_count *count, int rra, int rrb, char c);
void set_ra_rrb(t_count *count, int ra, int rrb, char c);
void set_rra_rb(t_count *count, int rra, int rb, char c);
void set_ra_rra(t_count *count, int ra, int rra, char c);
void set_rb_rrb(t_count *count, int rb, int rrb, char c);
void ft_set_count(t_list *lst, int best_move, char c);
int ft_set_best_move(t_list* lst);

void ft_swap(t_list **lst);
void ft_swap_end(t_list **lst);
void ft_swap_start(t_list **lst);
void ft_push(t_list **lst, t_list **lst_target);

t_list *ft_mark(t_list *ref, t_list *last, t_list *lst, t_list *next);
t_list *ft_set_mark(t_list *lst, t_list *ref);
int ft_mark_clean(t_list *lst, int n);
int		ft_len_order(t_list *start, t_list *last, t_list *lst, t_list *next, int len);
void		ft_find_order(t_list *lst);

int clean_a(t_pile *pile);
int clean_b(t_pile *pile);
t_list *ft_find_next_move(t_list *lst);
void ft_create_count(t_list *lst, t_list *lst_target, char c);
t_list *ft_find_targetb(t_list *lst, t_list *lst_target);
t_list *ft_find_targeta(t_list *lst, t_list *lst_target);
void ft_put_move(t_list *move, t_list **lst, t_list **lst_target, t_move **mvt);

void ft_do_move(void (*f)(t_list **), t_list **arg, int n);
void ft_move_1(t_list **mv, t_list **lst, t_move **mvt);
void ft_move_2(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt);
void ft_move_3(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt);
void ft_move_4(t_count *count, t_list **lst, t_list **lst_target, t_move **mvt);
void ft_move_first(t_list *first, t_list **lst, t_move **mvt);

void lst_first_place(t_pile *pile);
void ft_print_move(t_move *move);


int		error_int(char *s, int i);
t_list	*error_lst(char *s);
void	error_void(char *s, t_pile *pile, int i);

void	ft_free_lst(t_list *lst);
void    ft_free_move(t_move *move);
void    ft_free_pile(t_pile *pile, int i);

#endif