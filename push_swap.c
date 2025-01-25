/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:23:56 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/25 20:18:20 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !(*stack_a))
		return;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp);
	printfd(1, "pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !(*stack_b))
		return;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, temp);
	printfd(1, "pa\n");
}
