/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:24:18 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/02 15:38:22 by ahakki           ###   ########.fr       */
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
}

void	rra_rrb(t_list **a, int c)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = ft_lstlast(*a);
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	tmp->next = *a;
	*a = tmp;
	last->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra_rrb(a, 's');
	rra_rrb(b, 's');
}
