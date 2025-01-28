/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:36:20 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/28 13:41:16 by ahakki           ###   ########.fr       */
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

int		ft_isdayz(char *s, t_list **lst);
int		ft_isdouble(t_list **lst);
void	ft_sortedarr(int *arr, t_list *a, int i);

//linked list function
void	pb_pa(t_list **stack_a, t_list **stack_b, char c);
void	sa_sb(t_list **a, char c);
void	ftc(t_list *lst);
void	swap(t_list **a, t_list **b);
void	ra_rb(t_list **a, int c);
void	rr(t_list **a, t_list **b);
void	rra_rrb(t_list **a, int c);

#endif