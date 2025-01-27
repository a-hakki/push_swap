/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/27 17:09:23 by ahakki           ###   ########.fr       */
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

void	ft_swaped(t_list **stack_a, t_list **stack_b, int *arr, int i)
{
	int	start;
	int	end;
	int	offset;

	if (i <= 100 && i)
		offset = i / 6;
	else if (i > 100)
		offset = i / 10;
	else
		offset = 1;
	start = 0;
	end = offset;
	while (*stack_a)
	{
		if ((*stack_a)->content <= arr[start])
		{
			pb_pa(stack_a, stack_b, 'b');
			ra_rb(stack_b, 'b');
		}
		else if ((*stack_a)->content > arr[start] && (*stack_a)->content <= arr[end])
		{
			pb_pa(stack_a, stack_b, 'b');
			if ((*stack_b)->next && (*stack_b)->content < (*stack_b)->next->content)
				sa_sb(stack_b, 'b');
			if (end < i - 1)
				end++;
			if (start + 1 < end)
				start++;
		}
		else
			ra_rb(stack_a, 'a');
	}
}

void	ft_sorted(t_list **stack_a, t_list **stack_b, int i)
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
		i--;
	}
}

int main(int ac, char **av)
{
	int		i;
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	// t_list	*temp;

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
		return (ft_clear(stack_a), 0);
	ft_sortedarr(arr, stack_a, i);
	ft_swaped(&stack_a, &stack_b, arr, i);
	ft_sorted(&stack_a, &stack_b, i);
	// temp = stack_a;
	// while (temp)
	// {
	// 	printfd(1, "%d\n", temp->content);
	// 	temp = temp->next;
	// }
	// Clean up
	ft_clear(stack_a);
	ft_clear(stack_b);
	free(arr);
	return (0);
}
