/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonlydigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:01:13 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/24 15:48:59 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isonlydigit(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '\0' || av[i] == '+' || av[i] == '-')
		return (0);
	while (ft_isdigit(av[i]))
		i++;
	if (!av[i])
		return (1);
	return (0);
}