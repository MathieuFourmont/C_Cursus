/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:06:41 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 16:28:31 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **to, t_list **from)
{
	t_list	*curr_top;
	t_list	*new_top;

	if (!*from)
		return ;
	curr_top = *from;
	new_top = (*from)->next;
	curr_top->next = NULL;
	ft_lstadd_front(to, curr_top);
	*from = new_top;
}

void	pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
