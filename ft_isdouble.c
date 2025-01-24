/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:45:59 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/24 22:05:33 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_isdouble(t_list **lst)
{
	t_list	*temp;
	t_list	*checker;

	temp = *lst;
	while (temp)
	{
		checker = temp->next;
		while (checker)
		{
			if (temp->content == checker->content)
				return (ft_clear(*lst), printfd(2, "Error\n"), exit(1), 0);
			checker = checker->next;
		}
		temp = temp->next;
	}
	return (1);
}