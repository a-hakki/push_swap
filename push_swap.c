/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:23:56 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/26 20:19:29 by ahakki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb_pa(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*temp;

	if (!stack_a || !(*stack_a))
		return;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp);
	if (c == 'b')
		printfd(1, "pb\n");
	if (c == 'a')
		printfd(1, "pa\n");
}

void	sa_sb(t_list **a, char c)
{
	int	temp;
	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	swap(t_list **a, t_list **b)
{
	sa_sb(a, 's');
	sa_sb(b, 's');
	write(1, "ss\n", 3);
}
void    ra_rb(t_list **a, int c)
{
    t_list    *tmp;

    tmp = *a;
    *a = tmp->next;
    ft_addback(a, tmp);
    tmp->next = NULL;
    if (c == 'a')
        write(1, "ra\n", 3);
    if (c == 'b')
        write(1, "rb\n", 3);
}

void    rr(t_list **a, t_list **b)
{
    ra_rb(a, 's');
    ra_rb(b, 's');
    write(1, "rr\n", 3);
}