/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/26 20:26:26 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void	ft_sorted(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	int	start;
	int	end;
	int	offset;

	if (i <= 100 && i >=6)
		offset = i / 6;
	else if (i > 100)
		offset = i / 12;
	else
		offset = 1;
	start = 0;
	end = offset;
	while ((*stack_a))
	{
		if ((*stack_a)->content < arr[start])
		{
			pb_pa(stack_a, stack_a, 'b');
			ra_rb(stack_b, 'b');
		}
		if ((*stack_a)->content >= arr[start] && (*stack_a)->content < arr[end])
		{
			pb_pa(stack_a, stack_a, 'b');
			if ((*stack_b)->content < (*stack_a)->next->content)
				sa_sb(stack_b, 'b');
			if (end < i - 1)
				end ++;
			if (start + 1 < end)
				start++;
		}
		if ((*stack_a)->content > arr[start])
			ra_rb(stack_a, 'a');
	}
	
}

int main(int ac, char **av)
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
	arr = (int *)(malloc(i * sizeof(int)));
	if (!arr)
		return (ft_clear(stack_a), ft_clear(stack_b), 0);
	ft_sortedarr(arr, stack_a, i);
	ft_sorted(&stack_a, &stack_b, arr, i);
	
	return (ft_clear(stack_a), ft_clear(stack_b), free(arr), 0);
}
