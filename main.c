/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/26 22:31:40 by ahakki           ###   ########.fr       */
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

	if (i <= 100 && i >= 5)
		offset = i / 5;
	else if (i > 100)
		offset = i / 16;
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
			if ((*stack_b)->next)
				if ((*stack_b)->content < (*stack_b)->next->content)
					sa_sb(stack_b, 'b');
			if (end < i - 1)
				end ++;
			if (start + 1 < end)
				start++;
		}
		else if ((*stack_a)->content > arr[start])
			ra_rb(stack_a, 'a');
	}
}

void	ft_sorted(t_list **stack_a, t_list **stack_b, int i)
{	
	t_list	*temp;
	int		pos;
	int		index;

	temp = (*stack_b);
	pos = 0;
	pos = 0;
	while (*stack_b)
	{
		if (temp->content < (*stack_b)->content)
		{
			temp = (*stack_b);
			index = pos;
		}
		(*stack_b) = (*stack_b)->next;
		pos++;
		
		if (pos == i)
		{
			if (index < i / 2)
			{
				printfd(1, "---bigger---\n");
				pb_pa(stack_b, stack_a, 'a');
			}
			else
			{
				printfd(1, "---smaller---\n");
				rra_rrb(stack_b, 'b');
				pb_pa(stack_b, stack_a, 'a');
			}
		}
	}
}

int main(int ac, char **av)
{
	int		i;
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

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
	ft_swaped(&stack_a, &stack_b, arr, i);
	ft_sorted(&stack_a, &stack_b, i);
	temp = stack_a;
	while (temp)
	{
		printfd(1, "%d\n", temp->content);
		temp = temp->next;
	}
	return (ft_clear(stack_b), ft_clear(temp), free(arr), 0);
}
