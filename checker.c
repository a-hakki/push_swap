/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:48 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 11:06:18 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_language(char *buffer, t_list **a, t_list **b)
{
	if (ft_strncmp(buffer, "sa", 3) == 0)
		sa_sb(a, 's');
	if (ft_strncmp(buffer, "sb", 3) == 0)
		sa_sb(b, 's');
	if (ft_strncmp(buffer, "ss", 3) == 0)
		swap(b, a);
	if (ft_strncmp(buffer, "ra", 3) == 0)
		ra_rb(b, 's');
	if (ft_strncmp(buffer, "rb", 3) == 0)
		ra_rb(b, 's');
	if (ft_strncmp(buffer, "rr", 3) == 0)
		rr(b, a);
	if (ft_strncmp(buffer, "rra", 3) == 0)
		rra_rrb(a, 's');
	if (ft_strncmp(buffer, "rrb", 3) == 0)
		rra_rrb(b, 's');
	if (ft_strncmp(buffer, "rrb", 3) == 0)
		rrr(b, a);
}

int	ft_checker(t_list **stack_a, int i)
{
	t_list	*temp;

	if (i == 1)
		return (ftc(*stack_a), exit(0), 0);
	temp = *stack_a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return ((ftc(*stack_a), printfd(1, "KO\n") , exit(1), 0));
		temp = temp->next;
	}
	return (ftc(*stack_a), printfd(1, "OK\n") ,exit(0), 0);
}

int	main(int ac, char **av)
{
	int		i;
	char	*buffer;
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
	buffer = get_next_line(0);
	while (buffer)
	{
		push_swap_language(buffer, &stack_a, &stack_b);
		free(buffer);
		buffer = get_next_line(0);
	}
	ft_checker(&stack_a, i);
	return (ftc(stack_a), ftc(stack_b), 0);
}