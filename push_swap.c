/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:05 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/22 11:28:42 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int     i;
    t_list  *lst = NULL;
    t_list  *temp;

    if (ac < 2)
        return (1);
    i = 1;
    while (i < ac)
        ft_lstadd_front(&lst, ft_lstnew(ft_atoi(av[i++])));
    temp = lst;
    while (lst)
    {
        printfd(1, "%d\n", lst->content);
        lst = lst->next;
    }
    while (temp)
    {
        lst = temp->next;
        free(temp);
        temp = lst;
    }
    return (0);
}
