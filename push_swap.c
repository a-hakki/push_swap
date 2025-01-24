/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/24 22:02:34 by ahakki           ###   ########.fr       */
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

int main(int ac, char **av)
{
	int		i;
	t_list	*lst = NULL;
	t_list	*temp;

	if (ac < 2)
		return (1);
	i = ac - 1;
	while (i > 0)
		ft_isdayz(av[i--], &lst);
	ft_isdouble(&lst);
	temp = lst;
	if (i != 0)
	{
		printfd(2, "Error\n");
		return (ft_clear(temp), 1);
	}
	while (lst)
	{
		printfd(1, "%d\n", lst->content);
		lst = lst->next;
	}
	return (ft_clear(temp), 0);
}
