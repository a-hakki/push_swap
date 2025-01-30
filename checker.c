/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:48 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 13:29:48 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_language(char *buffer, t_list **a, t_list **b)
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		return (sa_sb(a, 's'), 1);
	if (ft_strncmp(buffer, "sb\n", 3) == 0)
		return (sa_sb(b, 's'), 1);
	if (ft_strncmp(buffer, "ss\n", 3) == 0)
		return (swap(b, a), 1);
	if (ft_strncmp(buffer, "ra\n", 3) == 0)
		return (ra_rb(b, 's'), 1);
	if (ft_strncmp(buffer, "rb\n", 3) == 0)
		return (ra_rb(b, 's'), 1);
	if (ft_strncmp(buffer, "rr\n", 3) == 0)
		return (rr(b, a), 1);
	if (ft_strncmp(buffer, "rra\n", 4) == 0)
		return (rra_rrb(a, 's'), 1);
	if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		return (rra_rrb(b, 's'), 1);
	if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		return (rrr(b, a), 1);
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		return (pb_pa(b, a, 's'), 1);
	if (ft_strncmp(buffer, "pb\n", 3) == 0)
		return (pb_pa(a, b, 's'), 1);
	get_next_line(-1);
	return (ftc(*a), ftc(*b), printfd(1, "Error\n"), free(buffer), exit(1), 0);
}

int	ft_checker(t_list **a, t_list **b, int i)
{
	t_list	*temp;

	(void)i;
	temp = *a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return ((ftc(*a), ftc(*b), write(1, "\033[31mKO\n\033[0m", 8), exit(1), 0));
		temp = temp->next;
	}
	return (ftc(*a), ftc(*b), write(1, "\033[32mOK\n\033[0m", 8), exit(0), 0);
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
	ft_checker(&stack_a, &stack_b, i);
	return (ftc(stack_a), ftc(stack_b), 0);
}
