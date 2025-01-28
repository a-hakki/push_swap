/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/28 22:32:32 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_over5(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	ft_sortedarr(arr, *stack_a, i);
	ft_swaped(stack_a, stack_b, arr, i);
	ft_sorted(stack_a, stack_b, i);
}

int	ft_issorted(t_list **stack_a, int i)
{
	t_list	*temp;

	if (i == 1)
		return (ftc(*stack_a), exit(0), 0);
	temp = *stack_a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (ftc(*stack_a), exit(0), 0);
}

void	ft_under5(t_list **stack_a, t_list **stack_b, int i)
{
	(void)stack_b;
	if (i == 2)
		sa_sb(stack_a, 'a');
	// if (i == 3)
	// if (i == 4)
	// if (i == 5)
}

int	main(int ac, char **av)
{
	int		i;
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	i = ac - 1;
	while (i > 0)
		ft_isdayz(av[i--], &stack_a);
	ft_isdouble(&stack_a);
	i = ft_lstsize(stack_a);
	ft_issorted(&stack_a, i);
	arr = (int *)(malloc(i * sizeof(int)));
	if (!arr)
		return (ftc(stack_a), 0);
	if (i > 5)
		ft_over5(&stack_a, &stack_b, arr, i);
	else
		ft_under5(&stack_a, &stack_b, i);
	return (ftc(stack_a), ftc(stack_b), free(arr), 0);
}
