/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:36:20 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/29 16:04:12 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_libft/libft.h"

# include <stdlib.h>

typedef struct s_var
{
	int	start;
	int	end;
	int	i;
}	t_var;

typedef struct s_sort
{
	int	a;
	int	b;
	int	c;
}	t_sort ;

//parssing functions
int		ft_isdayz(char *s, t_list **lst);
int		ft_isdouble(t_list **lst);
void	ft_sortedarr(int *arr, t_list *a, int i);

//sorting functions
int		ft_issorted(t_list **stack_a, int i);
void	ft_pushtob(t_list **s_a, t_list **s_b, int *arr, t_var *var);
void	ft_swaped(t_list **stack_a, t_list **stack_b, int *arr, int i);
void	ft_pushtoa(t_list **stack_b, t_list **stack_a, int index, int i);
void	ft_sorted(t_list **stack_a, t_list **stack_b, int i);
void	push_swap4(t_list **a, t_list **b);
void	push_swap5(t_list **a, t_list **b);
void	push_swap3(t_list **head);

//linked list functions
void	pb_pa(t_list **stack_a, t_list **stack_b, char c);
void	sa_sb(t_list **a, char c);
void	ftc(t_list *lst);
void	swap(t_list **a, t_list **b);
void	ra_rb(t_list **a, int c);
void	rr(t_list **a, t_list **b);
void	rra_rrb(t_list **a, int c);

#endif