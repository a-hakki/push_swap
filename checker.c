/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:48 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 10:18:52 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_language(char *buffer, t_list **a, t_list **b)
{
	buffer = ft_strtrim(buffer, "\n");
	if (ft_strncmp(buffer, "sa", 3) == 0)
		sa_sb(a, 's');
	if (ft_strncmp(buffer, "sb", 3) == 0)
		sa_sb(b, 's');
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
		printfd(1, "here\n");
		buffer = get_next_line(0);
	}
	ft_issorted(&stack_a, i);
	return (ftc(stack_a), ftc(stack_b), 0);
}