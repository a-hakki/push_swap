/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:24:18 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/28 20:26:30 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_list **a, int c)
{
	t_list	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = tmp->next;
	ft_lstadd_back(a, tmp);
	tmp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra_rb(a, 's');
	ra_rb(b, 's');
	write(1, "rr\n", 3);
}

void	rra_rrb(t_list **a, int c)
{
	t_list	*tmp;
	t_list	*fin;

	if (!(*a) || !(*a)->next)
	{
		printfd(1, "here\n");
		return ;
	}
	tmp = ft_lstlast(*a);
	fin = *a;
	while (fin->next->next != NULL)
		fin = fin->next;
	tmp->next = *a;
	*a = tmp;
	fin->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
