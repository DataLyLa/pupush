#include "push_swap.h"

void ok(char *s)
{
    printf("%s : ok\n", s);
}

void print_lst_ld(t_list *lst)
{
    if(!lst)
    {
        printf("pile vide");
        return ;
    }
    while(lst)
    {
        printf("p : %ld- ", lst->num);
        lst = lst->next;
    }
    printf("\n");
}

void ft_print_lst(char *s, t_list *lst, char type)
{
    if (lst == NULL) return;

    t_list *start = lst;
    do
    {
        if (type == 'n')          // Afficher un entier
            printf(s, lst->num);
        else if (type == 'm')     // Afficher un long
            printf(s, lst->mark);
        else if(type == 't')
            printf(s, lst->top);
        else if(type == 'b')
            printf(s, lst->btm);
        else
            return;               // Type non pris en charge
        lst = get_next(lst);
    } while (lst != start);          // Condition de sortie : boucle tant que l'élément suivant n'est pas le début
}