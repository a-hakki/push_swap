/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:45:59 by ahakki            #+#    #+#             */
/*   Updated: 2025/02/01 20:44:54 by ahakki           ###   ########.fr       */
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
				return (ftc(*lst), printfd(2, "Error\n"), exit(1), 0);
			checker = checker->next;
		}
		temp = temp->next;
	}
	return (1);
}

static void	ft_feed(int *arr, t_list *a, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		arr[k] = a->content;
		a = a->next;
		k++;
	}
}

void	ft_sortedarr(int *arr, t_list *a, int i)
{
	int	k;
	int	j;
	int	temp;

	ft_feed(arr, a, i);
	k = 0;
	while (k < i - 1)
	{
		j = 0;
		while (j < i - k - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		k++;
	}
}
