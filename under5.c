/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:58:39 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 09:35:14 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap3(t_list **head)
{
	t_sort	num;

	num.a = (**head).content;
	num.b = (**head).next->content;
	num.c = (**head).next->next->content;
	if (num.b > num.a && num.b > num.c && num.a > num.c)
		rra_rrb(head, 'a');
	if (num.b > num.a && num.b > num.c && num.a < num.c)
	{
		rra_rrb(head, 'a');
		sa_sb(head, 'a');
	}
	if (num.c > num.a && num.c > num.b && num.a > num.b)
		sa_sb(head, 'a');
	if (num.a > num.b && num.a > num.c && num.b > num.c)
	{
		sa_sb(head, 'a');
		rra_rrb(head, 'a');
	}
	if (num.a > num.b && num.a > num.c && num.b < num.c)
		ra_rb(head, 'a');
}

int	find_min(t_list *a)
{
	t_list	*tmp;
	int		min;
	int		min_pos;
	int		pos;

	tmp = a;
	min = tmp->content;
	min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	move_to_top(t_list **a, int pos, char stack_name)
{
	if (pos <= ft_lstsize(*a) / 2)
		while (pos--)
			ra_rb(a, stack_name);
	else
		while (pos++ < ft_lstsize(*a))
			rra_rrb(a, stack_name);
}

void	push_swap5(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = find_min(*a);
	move_to_top(a, min_pos, 'a');
	pb_pa(a, b, 'b');
	if (ft_lstsize(*a) == 4)
	{
		min_pos = find_min(*a);
		move_to_top(a, min_pos, 'a');
		pb_pa(a, b, 'b');
	}
	push_swap3(a);
	pb_pa(b, a, 'a');
	if (ft_lstsize(*b) > 0)
		pb_pa(b, a, 'a');
}
