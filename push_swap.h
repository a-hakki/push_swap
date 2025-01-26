#ifndef FDF_H
# define FDF_H

# include "./ft_libft/libft.h"

# include <stdlib.h>

int		ft_isdayz(char *s, t_list **lst);
int		ft_isdouble(t_list **lst);
void	ft_sortedarr(int *arr, t_list *a, int i);

//linked list function
void	pb_pa(t_list **stack_a, t_list **stack_b, char c);
void	sa_sb(t_list **a, char c);
void	ft_clear(t_list *lst);
void	swap(t_list **a, t_list **b);
void    ra_rb(t_list **a, int c);
void    rr(t_list **a, t_list **b);

#endif