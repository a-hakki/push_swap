#ifndef FDF_H
# define FDF_H

# include "./ft_libft/libft.h"

# include <stdlib.h>

int		ft_isdayz(char *s, t_list **lst);
int		ft_isdouble(t_list **lst);

//linked list function
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ft_clear(t_list *lst);

#endif