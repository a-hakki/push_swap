/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:16:44 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 09:41:15 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushtob(t_list **s_a, t_list **s_b, int *arr, t_var *var)
{
	while (*s_a)
	{
		if ((*s_a)->content <= arr[var->start])
		{
			pb_pa(s_a, s_b, 'b');
			ra_rb(s_b, 'b');
			if (var->end < var->i - 1)
				var->end++;
			if (var->start + 1 < var->end)
				var->start++;
		}
		else if ((*s_a)->content > arr[var->start] && \
		(*s_a)->content <= arr[var->end])
		{
			pb_pa(s_a, s_b, 'b');
			if ((*s_b)->next && (*s_b)->content < (*s_b)->next->content)
				sa_sb(s_b, 'b');
			if (var->end < var->i - 1)
				var->end++;
			if (var->start + 1 < var->end)
				var->start++;
		}
		else
			ra_rb(s_a, 'a');
	}
}

void	ft_sorted1(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	t_var	var;

	if (i <= 100 && i)
		var.end = i / 6;
	else if (i > 100)
		var.end = i / 12;
	else
		var.end = 1;
	var.start = 0;
	var.i = i;
	ft_pushtob(stack_a, stack_b, arr, &var);
}

void	ft_pushtoa(t_list **stack_b, t_list **stack_a, int index, int i)
{
	if (index <= i / 2)
	{
		while (index-- > 0)
			ra_rb(stack_b, 'b');
	}
	else
	{
		while (index++ < i)
			rra_rrb(stack_b, 'b');
	}
	pb_pa(stack_b, stack_a, 'a');
}

void	ft_sorted2(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*temp;
	t_list	*max;
	int		pos;
	int		index;

	while (*stack_b)
	{
		temp = *stack_b;
		pos = 0;
		index = 0;
		max = temp;
		while (temp)
		{
			if (max->content < temp->content)
			{
				max = temp;
				index = pos;
			}
			temp = temp->next;
			pos++;
		}
		ft_pushtoa(stack_b, stack_a, index, i);
		i--;
	}
}
