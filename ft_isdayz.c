/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdayz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:40:45 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/24 22:59:37 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_atoi2(char const *str, t_list *lst)
{
	int		i;
	int		sign;
	size_t	n;

	i = 0;
	sign = 1;
	n = 0;
	if (!strncmp(str, "2147483648", 10))
		return (ft_clear(lst), printfd(2, "Error\n"), exit(1), 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
		if (n > 2147483648)
			return (ft_clear(lst), printfd(2, "Error\n"), exit(1), 0);
	}
	return (n * sign);
}

int	ft_isspace(char *av)
{
	int	i;

	i = 0;
	while(av[i])
	{
		if (av[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
int	ft_isdayz(char *s, t_list **lst)
{
	char	**spl;
	int		i;

	if (ft_isonlydigit(s))
		ft_lstadd_front(lst, ft_lstnew(ft_atoi2(s, *lst)));
	else if (ft_isspace(s))
	{
		spl = ft_split(s, ' ');
		if (!spl)
			return (ft_clear(*lst), printfd(2, "Error\n"), exit(1), 0);
		i = ft_arrlen(spl) - 1;
		while (i >= 0)
		{
			if (ft_isonlydigit(spl[i]))
				ft_lstadd_front(&*lst, ft_lstnew(ft_atoi2(spl[i], *lst)));
			else
				return (ft_clear(*lst), printfd(2, "Error\n"), exit(1), 0);
			i--;
		}
		ft_free("2", spl);
	}
	else
		return (ft_clear(*lst), printfd(2, "Error\n"), exit(1), 0);
	return (1);
}