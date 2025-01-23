/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:49:37 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/23 22:02:59 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		n = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(n, del);
	}
}
